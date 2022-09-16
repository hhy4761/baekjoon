#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int n,k;
int board[205][205];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct cmp{
    bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b){
        int x1,y1,z1,x2,y2,z2;
        tie(x1,y1,z1) = a;
        tie(x2,y2,z2) = b;
        if(x1 < x2) return false;
        else return true;
    }
};
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,cmp> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
            if(board[i][j] > 0){
                pq.push(make_tuple(board[i][j],i,j));
            }
        }
    }
    int s,x,y;
    cin >> s >> x >> y;
    while(s--){
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,cmp> tmp;
        while(!pq.empty()){
            int val,x,y;
            tie(val,x,y) = pq.top(); pq.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<1 or nx>n or ny<1 or ny>n) continue;
                if(board[nx][ny]>0) continue;
                board[nx][ny] = val;
                tmp.push(make_tuple(val,nx,ny));
            }
        }
        pq = tmp;
    }
    cout << board[x][y];
}