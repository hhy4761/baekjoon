#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,m,x,y,ans;
int board[55][55];
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};
int order[4] = {3,2,4,1};

void destroy(int d,int s){
    for(int i=1; i<=s; i++){
        int nx = x+dx[d]*i;
        int ny = y+dy[d]*i;
        board[nx][ny] = 0;
    }
}

queue<int> move(){
    int cnt = 0;
    int stride = 1;
    int cur_x,cur_y;
    queue<int> values;
    tie(cur_x,cur_y) = {x,y};
    while(!(cur_x==1 and cur_y==1)){
        for(int i=0; i<stride; i++){
            if(cur_x==1 and cur_y==1) break;
            cur_x += dx[order[cnt%4]];
            cur_y += dy[order[cnt%4]];
            if(board[cur_x][cur_y]!=0) values.push(board[cur_x][cur_y]);
        }
        cnt++;
        if(cnt%2==0) stride++;
    }
    return values;
}

queue<int> boom(queue<int> q){
    fill(board[1],board[n+1],0);
    queue<int> q2;
    bool exist_boom = true;
    while(exist_boom){
        while(!q2.empty()) q2.pop();
        exist_boom = false;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int cnt = 1;
            while(!q.empty() and cur == q.front()){
                cnt++;
                q.pop();
            }
            if(cnt < 4){
                for(int i=0; i<cnt; i++) q2.push(cur);
            }
            else{
                exist_boom = true;
                ans += cur*cnt;
            }
        }
        q = q2;
    }
    return q2;
}

void divide(queue<int> q){
    queue<int> q2;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        int cnt = 1;
        while(!q.empty() and cur == q.front()){
            cnt++;
            q.pop();
        }
        q2.push(cnt);
        q2.push(cur);
    }
    int cnt = 0;
    int stride = 1;
    int cur_x,cur_y;
    tie(cur_x,cur_y) = {x,y};
    while(!q2.empty() and !(cur_x ==1 and cur_y==1)){
        for(int i=0; i<stride; i++){
            cur_x += dx[order[cnt%4]];
            cur_y += dy[order[cnt%4]];
            board[cur_x][cur_y] = q2.front(); q2.pop();
            if(q2.empty()) break;
            if(cur_x == 1 and cur_y == 1) break;
        }
        cnt++;
        if(cnt%2==0) stride++;
    }
}

int main(){
    fastio
    cin >> n >> m;
    x = (n+1)/2;
    y = (n+1)/2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    while(m--){
        int d,s;
        cin >> d >> s;
        destroy(d,s);
        divide(boom(move()));
    }
    cout << ans;
}