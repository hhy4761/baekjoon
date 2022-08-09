#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int board[501][501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool vis[501][501];
int n,m,mx,ans;
int comb[250000];
void dfs(int x,int y,int score,int cur){
    if(cur==4){
        ans = max(score,ans);
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 or nx>=n or ny <0 or ny>=m)
            continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        dfs(nx,ny,score+board[nx][ny],cur+1);
        vis[nx][ny] = 0;
    }
}
void hshape(int x,int y){
    int res = 0;
    if(x > 0 and y >0 and x<n-1){ //ㅓ
        res = board[x][y] + board[x-1][y] + board[x+1][y] + board[x][y-1];
    }
    if(x > 0 and y >0 and y < m-1){ //ㅗ
        res = max(res, board[x][y] + board[x-1][y] + board[x][y+1] + board[x][y-1]);
    }
    if(x > 0 and x < n-1){ //ㅏ
        res = max(res, board[x][y] + board[x-1][y] + board[x+1][y] + board[x][y+1]);
    }
    if(y > 0 and y < m-1){ //ㅜ
        res = max(res, board[x][y] + board[x+1][y] + board[x][y-1] + board[x][y+1]);
    }
    ans = max(ans,res);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = 1;
            dfs(i,j,board[i][j],1);
            hshape(i,j);
            vis[i][j] = 0;
        }
    }
    cout << ans;
}