#include <iostream>
#include <string>
#include <deque>
#include <utility>

using namespace std;

int n,m;
int board[502][502];
bool vis[502][502];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int x,int y){
    deque<pair<int,int>> dq;
    dq.push_back({x,y});
    vis[x][y] = true;
    int count = 1;
    while(!dq.empty()){
        pair<int,int> cur = dq.front(); dq.pop_front();
        
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 or nx >=n or ny < 0 or ny >= m)
                continue;
            if(board[nx][ny] == 1 and !vis[nx][ny]){
                dq.push_back({nx,ny});
                vis[nx][ny] = true;
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);  
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> board[i][j];
    int max_val = 0;
    int total = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 1 and !vis[i][j]){
                int cnt = bfs(i,j);
                total++;
                max_val = max(max_val,cnt);
            }
        }
    }
    cout << total << "\n" << max_val << "\n";
}   