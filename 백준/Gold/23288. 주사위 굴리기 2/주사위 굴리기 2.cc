#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,m,k;
int board[25][25];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dice[4][3] = {
    {0,2,0},
    {4,1,3},
    {0,5,0},
    {0,6,0}
};

void move(int dir){
    if(dir==0){ // E
        int row[4] = {dice[3][1],dice[1][0],dice[1][1],dice[1][2]};
        rotate(row,row+(4-1),row+4);
        dice[3][1] = row[0];
        dice[1][0] = row[1];
        dice[1][1] = row[2];
        dice[1][2] = row[3];
    }
    else if(dir==1){ // S
        int row[4] = {dice[0][1],dice[1][1],dice[2][1],dice[3][1]};
        rotate(row,row+(4-1),row+4);
        dice[0][1] = row[0];
        dice[1][1] = row[1];
        dice[2][1] = row[2];
        dice[3][1] = row[3];
    }
    else if(dir==2){ // W
        int row[4] = {dice[3][1],dice[1][0],dice[1][1],dice[1][2]};
        rotate(row,row+1,row+4);
        dice[3][1] = row[0];
        dice[1][0] = row[1];
        dice[1][1] = row[2];
        dice[1][2] = row[3];
    }
    else{ // N
        int row[4] = {dice[0][1],dice[1][1],dice[2][1],dice[3][1]};
        rotate(row,row+1,row+4);
        dice[0][1] = row[0];
        dice[1][1] = row[1];
        dice[2][1] = row[2];
        dice[3][1] = row[3];
    }
}

int get_under(){
    return dice[3][1];
}

int bfs(int x, int y){
    queue<pair<int,int>> q;
    bool visited[25][25];
    fill(visited[0],visited[25],false);
    int total = 1;
    int cur = board[x][y];
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        tie(x,y) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 or nx > n or ny < 1 or ny > m) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] != cur) continue;
            visited[nx][ny] = 1;
            total++;
            q.push({nx,ny});
        }
    }
    return total;
}

int main(){
    fastio
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }
    int dir = 0; // 0 : 동 1 : 남 2 : 서 3 : 북
    int x = 1 , y = 1, ans = 0;
    while(k--){
        int nx = x,ny = y;

        if(dir == 0) ny++;
        else if(dir == 1) nx++;
        else if(dir == 2) ny--;
        else if(dir == 3) nx--;

        if(nx < 1 or nx > n or ny < 1 or ny > m){
            if(dir == 0) y--;
            else if(dir == 1) x--;
            else if(dir == 2) y++;
            else x++;
            dir = (4+dir+2) % 4;  
        } 
        else{
            x = nx; y = ny;
        }
        move(dir);
        
        ans += (board[x][y] * bfs(x,y));

        if(get_under() < board[x][y]){
            dir = (4+dir-1) % 4;
        }
        else if(get_under() > board[x][y]){
            dir = (4+dir+1) % 4;
        }
    }
    cout << ans;
}