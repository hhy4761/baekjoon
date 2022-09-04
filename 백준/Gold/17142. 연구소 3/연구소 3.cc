#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int board[55][55];
int totalBlank;
int ans = INT32_MAX;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> virusPos; // 바이러스 위치 

void bfs(vector<pair<int,int>> activate){
    int visited[n][n];
    int x,y,count;
    int numBlank = 0;
    fill(visited[0],visited[n],-1);
    queue<tuple<int,int,int>> q;
    for(auto& virus : activate){
        q.push(make_tuple(virus.first,virus.second,0));
        visited[virus.first][virus.second] = 0;
    }
    while(!q.empty()){
        tie(x,y,count) = q.front(); q.pop();
        if(totalBlank == numBlank){
            ans = min(ans,count);
            return;
        } 
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=n) continue; // 인덱스 초과
            if(visited[nx][ny] != -1 and visited[nx][ny] <= visited[x][y]+1) continue; // 이미 방문한 곳
            if(board[nx][ny]==1) continue;  // 벽
            if(board[nx][ny]==0) numBlank++; // 빈칸 개수 세기
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx,ny,count+1});
            if(totalBlank == numBlank){
                ans = min(ans,count+1);
                return;
            } 
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j]==2) virusPos.push_back({i,j});
            if(board[i][j] == 0) totalBlank++; // 빈 칸의 개수
        }
    }
    // N과 M이 충분히 작기에 완전탐색
    // 바이러스 총 개수에서 M개의 활성화 바이러스를 추출
    int totalVirus = virusPos.size();
    int comb[totalVirus];
    fill(comb,comb+m,1);
    fill(comb+m,comb+totalVirus,0);
    sort(comb,comb+totalVirus);
    do{
        vector<pair<int,int>> activate;
        for(int i=0; i<totalVirus; i++){
            if(comb[i] == 1){
                activate.push_back(virusPos[i]);
            }
        }
        bfs(activate);
    }while(next_permutation(comb,comb+totalVirus));
    if(ans != INT32_MAX) cout << ans;
    else cout << -1;
}