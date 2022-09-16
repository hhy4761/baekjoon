// #include <iostream>
// #include <tuple>
// #include <vector>
// using namespace std;

// int m,n,ans;
// int board[505][505];
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> m >> n;
//     for(int i=0; i<m; i++)
//         for(int j=0; j<n; j++)
//             cin >> board[i][j];
//     vector<pair<int,int>> stack;
//     stack.push_back({0,0});
//     while(!stack.empty()){
//         int x,y;
//         tie(x,y) = stack.back(); stack.pop_back();
//         for(int i=0; i<4; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
//             if(board[nx][ny] >= board[x][y]) continue;
//             if(nx == m-1 and ny == n-1){
//                 ans++;
//                 continue;
//             }
//             stack.push_back({nx,ny});
//         }
//     }
//     cout << ans;
// }

#include <iostream>
using namespace std;

int m,n,ans;
int board[505][505];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cache[505][505];

int dp(int x,int y){
    if(x==m-1 and y==n-1) return 1;
    
    int& ret = cache[x][y];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
        if(board[nx][ny] >= board[x][y]) continue;
        ret += dp(nx,ny);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    fill(cache[0],cache[505],-1);
    cout << dp(0,0);
}