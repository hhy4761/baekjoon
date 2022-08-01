#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <limits>
using namespace std;

string board[102];
int dist[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;
void bfs(int x,int y);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;
    for(int i=0;i<n;i++)
        cin >> board[i];
    for(int i=0;i<n;i++) fill(dist[i],dist[i]+m,INT32_MAX);
    bfs(0,0);
    cout << dist[n-1][m-1];
    
}

void bfs(int x,int y){
    queue<tuple<int,int,int>> q;
    int count = 1;
    q.push(make_tuple(x,y,count));
    while(!q.empty()){
        tuple<int,int,int> cur = q.front(); q.pop();
        int cur_x = get<0>(cur);
        int cur_y = get<1>(cur);
        int count = get<2>(cur);
        if(cur_x == n-1 and cur_y == m-1){
            break;
        }
        for(int i =0; i<4 ; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx < 0 or nx >= n or ny <0 or ny >=m)
                continue;
            if(board[nx][ny]=='1' and dist[nx][ny] > count+1){
                q.push(make_tuple(nx,ny,count+1));
                dist[nx][ny] = count+1;
            }
        }
    }
}