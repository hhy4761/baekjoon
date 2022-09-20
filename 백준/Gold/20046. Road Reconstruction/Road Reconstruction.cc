#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m,n;
int board[1010][1010];
bool visited[1010][1010];
bool isFinish;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct cmp{
    bool operator()(tuple<int,int,int>&a, tuple<int,int,int>&b){
        int x1,x2,x3,y1,y2,y3;
        tie(x1,x2,x3) = a;
        tie(y1,y2,y3) = b;
        return x1 > y1;
    }
};

void bfs(int x,int y){
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,cmp> pq;
    pq.push(make_tuple(board[x][y],x,y));
    while(!pq.empty()){
        int cost,x,y;
        tie(cost,x,y) = pq.top(); pq.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
            if(board[nx][ny] == -1) continue;
            if(visited[nx][ny]) continue;
            if(nx == m-1 and ny == n-1){ // 정답 조건
                cout << cost + board[nx][ny];
                isFinish = true;
                return;
            }
            visited[nx][ny] = true;
            pq.push(make_tuple(cost+board[nx][ny], nx,ny));
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    if(board[0][0]==-1) cout << -1;
    else{
        bfs(0,0);
        if(!isFinish) cout << -1;
    }
}