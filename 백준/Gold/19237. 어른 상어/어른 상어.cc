#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,m,k;
struct cmp{
    bool operator()(int a, int b){
        if(a < b) return false;
        return true;
    }
};
priority_queue<int,vector<int>,cmp> board[25][25];
int num_shark;
pair<int,int> smell[25][25];
int cur_dir[404];
int priority[404][5][5];
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};

void put_smell(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j].size() >= 1){
                smell[i][j] = {board[i][j].top(),k};
            }
        }
    }
}
void kick_out(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j].size() >=2){
                int last_shark = board[i][j].top();
                while(!board[i][j].empty()){
                    board[i][j].pop();
                    num_shark--;
                }
                board[i][j].push(last_shark);
                num_shark++;
            }
        }
    }
}
void move(){
    priority_queue<int,vector<int>,cmp> copy_board[25][25];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j].size() >= 1){
                int shark = board[i][j].top();
                vector<tuple<int,int,int>> my_smell;
                bool find_blank = false;
                for(int k=1; k<=4; k++){
                    int dir = priority[shark][cur_dir[shark]][k];
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if(nx < 1 or nx > n or ny < 1 or ny > n) continue; // 격자 범위 밖
                    if(smell[nx][ny].first > 0 and smell[nx][ny].first != shark) continue; // 다른 상어가 냄새 뿌린 곳
                    if(smell[nx][ny].first == shark) my_smell.push_back(make_tuple(nx,ny,dir)); // 현재 상어가 냄새 뿌린 곳
                    if(smell[nx][ny].first == 0){ // 빈 곳
                        copy_board[nx][ny].push(shark);
                        cur_dir[shark] = dir;
                        find_blank = true;
                        break;
                    }
                }
                if(!find_blank){ // 빈 곳을 찾지 못했을 때
                    int x,y,dir;
                    tie(x,y,dir) = my_smell[0];
                    copy_board[x][y].push(shark);
                    cur_dir[shark] = dir;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            board[i][j] = copy_board[i][j];
        }
    }
}
void smell_count(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(smell[i][j].second >=1){
                smell[i][j].second--;
                if(smell[i][j].second == 0){
                    smell[i][j].first = 0;
                }
            } 
        }
    }
}

void print_shark(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << board[i][j].size() <<" ";
        }
        cout << "\n";
    }
}

int main(){
    fastio
    cin >> n >> m >> k;
    num_shark = m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int num;
            cin >> num;
            if(num > 0) board[i][j].push(num);
        }
    }
    for(int i=1; i<=m; i++){
        cin >> cur_dir[i];
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            priority[i][j][1] = a;
            priority[i][j][2] = b;
            priority[i][j][3] = c;
            priority[i][j][4] = d;
        }
    }
    int cnt = 0;
    while(cnt <= 1000 and num_shark > 1){
        put_smell();
        move();
        kick_out();
        smell_count();
        cnt++;
    }
    if(cnt > 1000) cout << -1;
    else cout << cnt;
}