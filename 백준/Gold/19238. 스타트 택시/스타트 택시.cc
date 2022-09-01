#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// n = board 크기
// m = 승객 수
// e = 연료
int n,m,e;
int board[25][25];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
struct driver{
    int x,y;
};
driver d;
unordered_map<int,vector<int>> um;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first > b.first) return false;
    else if(a.first < b.first) return true;
    else if(a.second < b.second) return true;
    else return false;
}

void drive(int x,int y,int destX, int destY){
    queue<tuple<int,int,int>> q;
    bool visited[n+1][n+1];
    int count = 0;
    fill(visited[0],visited[n+1],false);
    q.push(make_tuple(x,y,0));
    while(!q.empty()){
        int x,y;
        tie(x,y,count) = q.front(); q.pop();
        if(x == destX and y == destY){
                e -= count+1;
                if(e >= 0){ // success
                    e += 2*(count+1);
                    m--;
                    d.x = x;
                    d.y = y;
                    return;
                }
                else{ // fail
                    return;
                }
            }
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<1 or nx>n or ny<1 or ny>n) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny]==1) continue;
            if(nx == destX and ny == destY){
                e -= count+1;
                if(e >= 0){ // success
                    e += 2*(count+1);
                    m--;
                    d.x = nx;
                    d.y = ny;
                    return;
                }
                else{ // fail
                    return;
                }
            }
            visited[nx][ny] = true;
            q.push(make_tuple(nx,ny,count+1));
        }
    }
    e -= count;
}

void pickup(driver d){
    queue<tuple<int,int,int>> q;
    vector<pair<int,int>> cand;
    bool visited[n+1][n+1];
    int count = 0;
    int maxCount = 500001;
    fill(visited[0],visited[n+1],false);
    q.push(make_tuple(d.x,d.y,0));
    while(!q.empty()){
        int curX,curY;
        tie(curX,curY,count) = q.front(); q.pop();
        if(count >= e){
            e -= count;
            return;
        }
        if(!um[curX*n+curY].empty()){
            maxCount = count;
            cand.push_back({curX,curY});
        }
        for(int i=0; i<4; i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            if(nx<1 or nx>n or ny<1 or ny >n) continue;
            if(visited[nx][ny]) continue;
            if(maxCount < count+1) break;
            if(board[nx][ny]==1) continue;
            if(!um[nx*n+ny].empty()){ // 승객 찾음
                maxCount = count + 1;
                cand.push_back({nx,ny});
            }
            visited[nx][ny] = 1;
            q.push(make_tuple(nx,ny,count+1));
        }
    }
    if(!cand.empty()){
        sort(cand.begin(),cand.end(),cmp);
        e -= maxCount;
        drive(cand[0].first,cand[0].second,um[cand[0].first*n+cand[0].second][0],um[cand[0].first*n+cand[0].second][1]);
        um[cand[0].first*n+cand[0].second].clear();
        return;
    }
    e -= count;
    if(count == 0){
        e = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> e;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    int x,y;
    cin >> x >> y;
    d.x = x, d.y = y;
    for(int i=0; i<m; i++){
        int x,y,destX,destY;
        cin >> x >> y >> destX >> destY;
        um[x*n+y].push_back(destX);
        um[x*n+y].push_back(destY);
    }
    while(true){
        if(e<=0){
            cout << -1;
            return 0;
        }
        else if(m==0) break;
        pickup(d);
        // break;
        
    }
    cout << e;
}