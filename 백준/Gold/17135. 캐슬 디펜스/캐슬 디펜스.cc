#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m,d,ans;
int board[20][20];
int tempBoard[20][20];
int dx[4] = {0,1,-1,0};
int dy[4] = {-1,0,0,1};
vector<pair<int,int>> deleted;
void printArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << board[i][j] << ' ';
        }
        cout << "\n";
    }
}
void moveEnemy(){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
            if(board[i][j]==1){
                if(i==n-1) board[i][j] = 0;
                else{
                    board[i][j] = 0;
                    board[i+1][j] = 1;
                }
            }
        }
    }
}
void shotEnemy(int curX, int curY){
    queue<pair<int,int>> q;
    int visited[25][25];
    bool find = false;
    fill(visited[0],visited[25],-1);

    q.push({curX,curY});
    visited[curX][curY] = 0;

    while(!q.empty() and !find){
        int x,y;
        tie(x,y) = q.front(); q.pop();

        if(visited[x][y] == d) break;

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
            if(visited[nx][ny] != -1) continue;
            if(board[nx][ny] == 1){
                deleted.push_back({nx,ny});
                find = true;
                break;
            }
            visited[nx][ny] = visited[x][y]+1;
            q.push({nx,ny});
        }
    }
}
bool existEnemy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 1)    return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> d;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    bool comb[m];
    fill(comb,comb+3,1);
    fill(comb+3,comb+m,0);
    sort(comb,comb+m);
    int maxAns = 0;
    do{
        vector<pair<int,int>> archer;
        for(int i=0; i<m; i++){ // archer 배치
            if(comb[i] == 1){   
                archer.push_back({n,i});
            }
        }
        ans = 0;
        copy(board[0],board[20],tempBoard[0]);
        while(existEnemy()){
            deleted.clear();
            for(int i=0;i<archer.size(); i++){
                shotEnemy(archer[i].first,archer[i].second);
            }
            for(int i=0; i<deleted.size(); i++){
                if(board[deleted[i].first][deleted[i].second] == 1){
                    board[deleted[i].first][deleted[i].second] = 0;
                    ans++;
                }
            }
            moveEnemy();
        }
        maxAns = max(maxAns, ans);
        copy(tempBoard[0],tempBoard[20],board[0]);
    }while(next_permutation(comb,comb+m));
    cout << maxAns;
}


