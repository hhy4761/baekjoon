#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int n,ans,ans2;
int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};
int board[12][12];
int visited[12][12];
void setVisit(int x, int y){
    visited[x][y]++;
    int count = n - min(x,y);
    for(int i=1; i<=count; i++){
        for(int j=0; j<4; j++){
            int nx = x + i*dx[j];
            int ny = y + i*dy[j];
            if(nx < 1 or nx > n or ny < 1 or ny > n) continue;
            visited[nx][ny]++;
        }
    }
}
void unsetVisit(int x, int y){
    visited[x][y]--;
    int count = n - min(x,y);
    for(int i=1; i<=count; i++){
        for(int j=0; j<4; j++){
            int nx = x + i*dx[j];
            int ny = y + i*dy[j];
            if(nx < 1 or nx > n or ny < 1 or ny > n) continue;
            visited[nx][ny]--;
        }
    }
}
bool check(int x,int y){
    if(board[x][y]==0) return false;
    if(visited[x][y] > 0) return false;
    return true;
}

void dfs(int x, int y, int cur){
    ans = max(ans,cur);
    for(int i=x; i<=n; i++){
        for(int j=1; j<=n; j++){
            if((i+j) % 2==0) continue;
            if(check(i,j)){
                setVisit(i,j);
                dfs(i,j,cur+1);
                unsetVisit(i,j);
            }
        }
    }
}
void dfs2(int x, int y, int cur){
    ans2 = max(ans2,cur);
    for(int i=x; i<=n; i++){
        for(int j=1; j<=n; j++){
            if((i+j) % 2!=0) continue;
            if(check(i,j)){
                setVisit(i,j);
                dfs2(i,j,cur+1);
                unsetVisit(i,j);
            }
        }
    }
}
int main(){
    fastio
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    dfs(1,1,0);
    fill(visited[0],visited[12],0);
    dfs2(1,1,0);
    // cout << ans;
    // cout << "\n";
    // cout << ans2;
    cout << ans + ans2;
}