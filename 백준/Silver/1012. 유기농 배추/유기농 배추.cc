#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int t,n,m,k;
bool board[50][50];
bool vis[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m or vis[nx][ny] or !board[nx][ny]) 
                continue;
            vis[nx][ny] =true;
            q.push({nx,ny});
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        cnt = 0;
        fill(board[0],board[50],false);
        fill(vis[0],vis[50],false);
        for(int i=0; i<k; i++){
            int x,y;
            cin >> y >> x;
            board[x][y] = 1;
        }
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 1 and !vis[i][j]){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    
}