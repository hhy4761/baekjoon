#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int board[305][305];
int tempBoard[305][305];
bool visited[305][305];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int checkAround(int x,int y){
    int cnt=0;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
        if(board[nx][ny] == 0) cnt++;
    }
    return cnt;
}

void melting(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] != 0){
                int num = checkAround(i,j);
                tempBoard[i][j] = board[i][j] - num;
                if(tempBoard[i][j] < 0) tempBoard[i][j] = 0;
            }
        }
    }
    copy(tempBoard[0],tempBoard[305],board[0]); // 임시 배열 -> 원래 배열
    fill(tempBoard[0],tempBoard[305],0); // 임시 배열 초기화
}

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        tie(x,y) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 or nx>= n or ny<0 or ny>=m) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] ==0 )continue;
            q.push({nx,ny});
            visited[nx][ny] = true;
        }
    }
}

int chunk(){
    int cnt=0;
    fill(visited[0],visited[305],false);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] != 0 and !visited[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

void printArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n;i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    int ans = 0;
    while(true){
        ans++;
        melting();
        // printArr();
        int chunks = chunk();
        if(chunks == 0){
            cout << 0;
            return 0;
        }
        else if(chunks >= 2){
            cout << ans;
            return 0;
        }
    }
}