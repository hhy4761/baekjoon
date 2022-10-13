#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<int> board[5][5];
vector<int> copy_vector[5][5];
int smell[5][5];
int m,s,ans;
//←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int order[5] = {2,0,6,4};
int s_x,s_y;
bool visited[5][5];
vector<pair<int,int>> traces;
vector<pair<int,int>> trace;
int maxCount;
void copy_fish(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            copy_vector[i][j] = board[i][j];
        }
    }
}

void move_fish(){
    vector<int> v[5][5];
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            for(auto& e: board[i][j]){
                bool find = false;
                for(int k=0; k<8; k++){
                    int nx = i+dx[(8+e-k)%8];
                    int ny = j+dy[(8+e-k)%8];
                    if(nx < 1 or nx > 4 or ny <1 or ny > 4) continue;
                    if(smell[nx][ny] > 0) continue;
                    if(nx == s_x and ny == s_y) continue;
                    v[nx][ny].push_back((8+e-k)%8);
                    find = true;
                    break;
                }
                if(!find) v[i][j].push_back(e);
            }
        }
    }
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            board[i][j] = v[i][j];
        }
    }
}

void move_shark(int x,int y,int cur, int cnt){
    // cout << x << y;
    if(cur==3){
        if(maxCount < cnt){
            maxCount = cnt;
            trace = traces;
            s_x = x;
            s_y = y;
        }
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x+dx[order[i]];
        int ny = y+dy[order[i]];
        if(nx < 1 or nx > 4 or ny < 1 or ny > 4) continue;

        if(!visited[nx][ny]){
            traces.push_back({nx,ny});
            visited[nx][ny] = true;
            move_shark(nx,ny,cur+1,cnt+board[nx][ny].size());
            visited[nx][ny] = false;
            traces.pop_back();
        } 
        else{
            move_shark(nx,ny,cur+1,cnt);
        }
    }
}

void erase_fish(){
    for(auto& e : trace){
        if(board[e.first][e.second].size() >= 1){
            board[e.first][e.second].clear();
            smell[e.first][e.second] = 3;
        }
    }
}

void smell_count(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            if(smell[i][j] > 0) smell[i][j]--;
        }
    }
}

void paste_fish(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            board[i][j].insert(board[i][j].end(),copy_vector[i][j].begin(),copy_vector[i][j].end());
        }
    }
}

void print(){
    for(int i = 1;i<=4; i++){
        for(int j=1; j<=4; j++){
            // cout << board[i][j].size() << " ";
            ans += board[i][j].size();
        }
        // cout << "\n";
    }
    cout << ans;
}

int main(){
    fastio
    cin >> m >> s;
    for(int i=0; i<m; i++){
        int x,y,d;
        cin >> x >> y >> d;
        board[x][y].push_back(d-1);
    }
    cin >> s_x >> s_y;
    while(s--){
        maxCount = -1;
        fill(visited[0],visited[5],false);
        traces.clear(); trace.clear();
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                copy_vector[i][j].clear();
            }
        }
        copy_fish();
        move_fish();
        move_shark(s_x,s_y,0,0);
        erase_fish();
        smell_count();
        paste_fish();
    }
    print();
    // cout << s_x << " " << s_y;
    // for(auto& e : board[4][4]){
    //     cout << e << " ";
    // }
}