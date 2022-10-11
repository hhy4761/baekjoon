#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,m;
int board[55][55];
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
vector<pair<int,int>> clouds;

void move(int d, int s){
    for(auto& e : clouds){
        int nx = e.first + dx[d]*s;
        int ny = e.second + dy[d]*s;
        nx = nx % n;
        ny = ny % n;
        if(nx<=0) nx += n;
        if(ny<=0) ny += n;
        e.first = nx;
        e.second = ny;
    }
}

void rain_copy(){
    for(auto& e : clouds){
        board[e.first][e.second]++;
    }
    for(auto& e : clouds){
        int cnt = 0;
        for(auto& i : {2,4,6,8}){
            int nx = e.first + dx[i];
            int ny = e.second + dy[i];
            if(nx < 1 or nx > n or ny < 1 or ny > n) continue;
            if(board[nx][ny] >= 1) cnt++;
        }
        board[e.first][e.second] += cnt;
    }
}

void make_clouds(){
    vector<pair<int,int>> tmp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] >= 2){
                if(find(clouds.begin(),clouds.end(),make_pair(i,j))==clouds.end()){
                    board[i][j]-=2;
                    tmp.push_back({i,j});
                }
            }
        }
    }
    clouds.clear();
    clouds = tmp;
}

int main(){
    fastio
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    // 구름 초기값
    clouds.push_back({n-1,1});
    clouds.push_back({n-1,2});
    clouds.push_back({n,1});
    clouds.push_back({n,2});
    while(m--){
        // d :  ←, ↖, ↑, ↗, →, ↘, ↓, ↙
        int d,s;
        cin >> d >> s;
        move(d,s);
        rain_copy();
        make_clouds();
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans += board[i][j];
        }
    }
    cout << ans;
}