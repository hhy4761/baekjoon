#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,q,ans;
int N,L;
int board[70][70];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void rotate_right(){
    for(int row=0; row<N; row+=L){
        for(int col=0; col<N; col+=L){
            queue<int> list;
            for(int i=1; i<=L; i++){
                for(int j=1; j<=L; j++){
                    list.push(board[row+i][col+j]);
                }
            }
            for(int j=L; j>=1; j--){
                for(int i=1; i<=L; i++){
                    board[row+i][col+j] = list.front(); list.pop();
                }
            }
        }
    }
}

void reduce_ice(){
    vector<pair<int,int>> reduce_cands;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int cnt = 0;
            for(int k=0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx < 1 or nx > N or ny < 1 or ny > N) continue;
                if(board[nx][ny] > 0) cnt++;
            }
            if(cnt < 3) reduce_cands.push_back({i,j});
        }
    }
    for(auto& e : reduce_cands){
        board[e.first][e.second]--;
        if(board[e.first][e.second] < 0) board[e.first][e.second] = 0;
    }
}

int get_total_ice(){
    int total = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            total+=board[i][j];
        }
    }
    return total;
}

int get_max_chunk(){
    bool visited[70][70];
    fill(visited[0],visited[70],false);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(board[i][j] > 0 and !visited[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;
                int cur_chunk = 1;
                while(!q.empty()){
                    int x,y;
                    tie(x,y) = q.front(); q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(nx < 1 or nx > N or ny < 1 or ny > N) continue;
                        if(visited[nx][ny]) continue;
                        if(board[nx][ny] <= 0) continue;
                        visited[nx][ny] = 1;
                        cur_chunk++;
                        q.push({nx,ny});
                    }
                }
                ans = max(ans,cur_chunk);
            }
        }
    }
    return ans;
}

int main(){
    fastio
    cin >> n >> q;
    N = int(pow(2,n));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }
    while(q--){
        int l;
        cin >> l;
        L = int(pow(2,l));
        rotate_right();
        reduce_ice();
    }
    cout << get_total_ice() << "\n";
    cout << get_max_chunk();
}