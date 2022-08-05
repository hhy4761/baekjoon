#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
string board[100];
bool vis[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt_n; // 적록색맹 없음
int cnt_y; // 있음

void bfs_n(int x, int y){
    queue<pair<int,int>> q;
    vis[x][y] = true;
    q.push({x,y});
    char curcolor = board[x][y];
    while(!q.empty()){
        tie(x,y) = q.front(); q.pop();
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=n)
                continue;
            if(vis[nx][ny] or curcolor != board[nx][ny])
                continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    return;
}
void bfs_y(int x, int y){
    queue<pair<int,int>> q;
    vis[x][y] = true;
    q.push({x,y});
    char curcolor = board[x][y];
    while(!q.empty()){
        tie(x,y) = q.front(); q.pop();
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=n)
                continue;
            if(vis[nx][ny])
                continue;
            if((curcolor =='G' and board[nx][ny]=='R') or (curcolor == 'R' and board[nx][ny] == 'G') or curcolor == board[nx][ny]){
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }            
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> board[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j]){
                bfs_n(i,j);
                cnt_n++;
            }
        }
    }
    fill(vis[0],vis[100],false);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j]){
                bfs_y(i,j);
                cnt_y++;
            }
        }
    }
    cout << cnt_n << ' ' << cnt_y;
}