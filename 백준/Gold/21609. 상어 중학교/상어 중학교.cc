#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,m,ans;
int board[22][22];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool cmp(tuple<int,int,vector<pair<int,int>>> a, tuple<int,int,vector<pair<int,int>>> b){
    int size1,size2,rainbow1,rainbow2;
    vector<pair<int,int>> v1,v2;
    tie(size1,rainbow1,v1) = a;
    tie(size2,rainbow2,v2) = b;
    if(size1 < size2) return false;
    else if(size1 == size2){
        if(rainbow1 < rainbow2) return false;
        else if(rainbow1 == rainbow2){
            if(v1[0].first < v2[0].first) return false;
            else if(v1[0].first == v2[0].first){
                if(v1[0].second < v2[0].second) return false;
            }
        }
    }
    return true;
}

vector<tuple<int,int,vector<pair<int,int>>>> countBlocks(){
    bool visited[22][22];
    fill(visited[0],visited[22],false);
    vector<tuple<int,int,vector<pair<int,int>>>> blocks;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] > 0 and !visited[i][j]){
                vector<pair<int,int>> v;
                queue<pair<int,int>> q;
                int color = board[i][j];
                int rainbow = 0;
                q.push({i,j});
                visited[i][j] = 1;
                while(!q.empty()){
                    int x,y;
                    tie(x,y) = q.front(); q.pop();
                    v.push_back({x,y});
                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(nx<1 or nx>n or ny<1 or ny>n) continue;
                        if(visited[nx][ny]) continue;
                        if(board[nx][ny]==-1) continue;
                        if(board[nx][ny]==-9) continue;
                        if(board[nx][ny]>0 and board[nx][ny]!=color) continue;
                        if(board[nx][ny]==0) rainbow++;
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                // 블록이 2개 이상일 때만 후보에 넣어줌
                if(v.size() >= 2) blocks.push_back(make_tuple(v.size(),rainbow,v));
                // 무재개 블록은 사용안함으로 초기화
                for(int i=1; i<=n; i++){
                    for(int j=1; j<=n; j++){
                        if(board[i][j] == 0) visited[i][j] = 0;
                    }
                }
            }
        }
    }
    sort(blocks.begin(),blocks.end(),cmp);
    return blocks;
}

void eraseBlocks(vector<pair<int,int>> blocks){
    ans += blocks.size()*blocks.size();
    for(auto& e : blocks){
        board[e.first][e.second] = -9;
    }
}

void applyGravity(){
    for(int j=1; j<=n; j++){
        queue<int> q;
        for(int i=n; i>=1; i--){
            q.push(board[i][j]);
        }
        int cnt = n;
        while(!q.empty()){
            int cur = q.front();
            if(cur == -9){
                q.pop();
                continue;
            }
            else if(cur == -1){
                while(cnt != q.size()){
                    board[cnt][j] = -9;
                    cnt--;
                }
                cnt = q.size()-1;
                q.pop();
                continue;
            }
            board[cnt][j] = cur;
            cnt--;
            q.pop();
        }
        while(cnt != 0){
            board[cnt][j] = -9;
            cnt--;
        }
    }
}

void rotate_left(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            q.push(board[i][j]);
        }
    }
    for(int j=1; j<=n; j++){
        for(int i=n; i>=1; i--){
            board[i][j] = q.front(); q.pop();
        }
    }
}   

int main(){
    fastio
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    while(true){
        vector<tuple<int,int,vector<pair<int,int>>>> B = countBlocks();
        if(B.size() == 0) break;
        int size,rainbow;
        vector<pair<int,int>> blocks;
        tie(size,rainbow,blocks) = B[0];
        eraseBlocks(blocks);
        applyGravity();
        rotate_left();
        applyGravity();
    }
    cout << ans;
}