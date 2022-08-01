#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int board[1000][1000];
int bfs(vector<pair<int,int>> &p);

int main(){
    cin >> n >> m;
    vector<pair<int,int>> positions;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) positions.push_back({i,j});
        }
    }
    cout << bfs(positions) ;
}

int bfs(vector<pair<int,int>> &p){
    queue<pair<int,int>> q;
    int res = 0;
    for(const auto pos : p) q.push({pos.first,pos.second});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        if(board[cur.first][cur.second] > res) 
            res = board[cur.first][cur.second];
        for(int i=0; i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx<0 or nx>=m or ny<0 or ny>=n)
                continue;
            
            if(board[nx][ny]==0){
                board[nx][ny] = board[cur.first][cur.second] + 1;
                q.push({nx,ny});
            }
        }
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(board[i][j] == 0) return -1;
    return res-1;
}