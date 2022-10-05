#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,m,ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> pos;
string board[22];
bool visited1[22][22];
bool visited2[22][22];

void dfs(int x1, int y1, int x2, int y2, int cur, bool first, bool second){
    if(cur > 10) return;
    if(first or second){
        if(first and second) return; // 둘다 떨어진 경우
        ans = min(ans,cur);
        return;
    }
    for(int i=0; i<4; i++){
        int nx1 = x1+dx[i];
        int ny1 = y1+dy[i];
        int nx2 = x2+dx[i];
        int ny2 = y2+dy[i];
        bool success1 = false;
        bool success2 = false;
        if(nx1 < 0 or nx1 >= n or ny1 < 0 or ny1 >= m){ // 떨어지는 조건
            success1 = true;
        }
        if(nx2 < 0 or nx2 >= n or ny2 < 0 or ny2 >= m){
            success2 = true;
        }
        if(!success1 and board[nx1][ny1] == '#'){ // 이동하지 못하는 조건
            nx1 = x1;
            ny1 = y1;
        }
        if(!success2 and board[nx2][ny2] == '#'){
            nx2 = x2;
            ny2 = y2;
        }
        dfs(nx1,ny1,nx2,ny2,cur+1,success1,success2);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 'o') pos.push_back({i,j});
        }
    }
    ans = INT32_MAX;
    dfs(pos[0].first,pos[0].second,pos[1].first,pos[1].second,0,false,false);
    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
}