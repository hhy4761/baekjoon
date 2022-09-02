#include <iostream>
#include <deque>
#include <string>
#include <tuple>
using namespace std;

int n,m;
string board[105];
pair<int,int> visited[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<n;i++) cin >> board[i];
    fill(visited[0],visited[105],make_pair(10005,10005));
    deque<tuple<int,int,int>> q;
    q.push_front(make_tuple(0,0,0));
    visited[0][0] = {0,0};
    while(!q.empty()){
        int x,y,count;
        tie(x,y,count) = q.front(); q.pop_front();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
            if(board[nx][ny] == '1'){
                if(visited[nx][ny].second > visited[x][y].second+1){
                    visited[nx][ny] = {visited[x][y].first+1,visited[x][y].second+1};
                    q.push_back(make_tuple(nx,ny,count+1));
                }   
                else if(visited[nx][ny].second == visited[x][y].second+1){
                    if(visited[nx][ny].first > visited[x][y].first+1){
                        visited[nx][ny] = {visited[x][y].first+1,visited[x][y].second+1};
                        q.push_back(make_tuple(nx,ny,count+1));
                    }
                }
            }
            else{ // board[nx][ny] == '0'
                if(visited[nx][ny].second > visited[x][y].second){
                    visited[nx][ny] = {visited[x][y].first+1,visited[x][y].second};
                    q.push_front(make_tuple(nx,ny,count));
                }   
                else if(visited[nx][ny].second == visited[x][y].second){
                    if(visited[nx][ny].first > visited[x][y].first+1){
                        visited[nx][ny] = {visited[x][y].first+1,visited[x][y].second};
                        q.push_front(make_tuple(nx,ny,count));
                    }
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << visited[i][j].second << " ";
    //     }
    //     cout << "\n";
    // }
    cout << visited[n-1][m-1].second;
}