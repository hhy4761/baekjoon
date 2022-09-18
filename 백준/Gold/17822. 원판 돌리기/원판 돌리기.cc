#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m,t,ans,x,d,k;
int board[55][55];
bool visited[55][55];
bool isErased;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void go(int cur,int d,int k){
    if(d==1) rotate(board[cur]+1,board[cur]+k+1,board[cur]+m+1); // 반시계
    else rotate(board[cur]+1,board[cur]+(m-k)+1,board[cur]+m+1); // 시계
}
void erase(int i,int j){
    queue<pair<int,int>> q;
    vector<pair<int,int>> cand;
    q.push({i,j});
    cand.push_back({i,j});
    visited[i][j] = true;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <1 or nx>n) continue;
            if(ny < 1) ny = m;
            else if(ny > m) ny = 1;
            if(board[nx][ny] != board[x][y]) continue;
            if(visited[nx][ny]) continue;
            cand.push_back({nx,ny});
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    if(cand.size() > 1){
        for(auto& e : cand){
            // cout << board[e.first][e.second] << " ";
            // cout << e.first << " " << e.second << " ";
            board[e.first][e.second] = 0;
        }
        // cout << "\n";
        isErased = true;
    }
}
double avg(){
    double num =0 ,total= 0 ;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(board[i][j] > 0){
                num += board[i][j];
                total++;
            }
        }
    }
    return num/total;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }
    while(t--){
        cin >> x >> d >> k; // d = 0: 시계방향 d = 1: 반시계방향

        // 회전
        for(int i=1; i<=n; i++){
            int cur = x*i;
            if(cur > n) break;
            go(cur,d,k%m);
        }
        
        // 인접한 숫자 제거
        fill(visited[0],visited[55],false);
        isErased = false;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(!visited[i][j] and board[i][j] > 0){
                    erase(i,j);
                }
            }
        }
    
        // 인접한 숫자가 없을 때
        if(!isErased){
            double num = avg();
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(board[i][j] > 0){
                        if(board[i][j] < num) board[i][j]++;
                        else if(board[i][j] > num)board[i][j]--;
                    }
                }
            }
        }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // cout << board[i][j] << " ";
                ans += board[i][j];
            }
            // cout << "\n";
        }
        cout << ans;
}