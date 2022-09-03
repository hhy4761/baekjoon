#include <iostream>

using namespace std;

int n,ans;
int board[505][505];
int ux[4] = {0,1,0,-1};
int uy[4] = {-1,0,1,0};
int dx[4][10] = { // 왼쪽 아래 오른쪽 위 순서
    {-2,-1,-1,-1,0,1,1,1,2,0},
    {0,1,0,-1,2,1,0,-1,0,1},
    {2,1,1,1,0,-1,-1,-1,-2,0},
    {0,-1,0,1,-2,-1,0,1,0,-1}
};
int dy[4][10] = {
    {0,-1,0,1,-2,-1,0,1,0,-1},
    {-2,-1,-1,-1,0,1,1,1,2,0},
    {0,1,0,-1,2,1,0,-1,0,1},
    {2,1,1,1,0,-1,-1,-1,-2,0},
};
int ratio[10] = {2,10,7,1,5,10,7,1,2,55};
void moveSand(int r,int c,int dir){ // dir => 0: 좌 1:아래 2:우 3:위
    int initialValue = board[r][c];
    int total = 0;
    for(int i=0;i<9;i++){
        if(r+dx[dir][i] < 0 or r+dx[dir][i] >= n or c+dy[dir][i] < 0 or c+dy[dir][i] >=n){
            ans += (int)(initialValue*ratio[i]*0.01);
            total += (int)(initialValue*ratio[i]*0.01);
            continue;
        }
        board[r+dx[dir][i]][c+dy[dir][i]] += (int)(initialValue*ratio[i]*0.01);
        total += (int)(initialValue*ratio[i]*0.01);
    }
    board[r][c] = 0 ;
    if(r+dx[dir][9] <0 or r+dx[dir][9] >=n or c+dy[dir][9]<0 or c+dy[dir][9]>=n){
        ans += initialValue-total;
    }
    else board[r+dx[dir][9]][c+dy[dir][9]] += (initialValue - total);
}

// void PRINT(){
//     for(int i=0; i<n;i++){
//         for(int j=0; j<n; j++){
//             cout << board[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    int x = n/2, y = n/2, dir=0, count=1;
    while(true){
        if(x==0 and y==0) break;
        for(int k=0; k<2; k++){
            for(int i=count; i<count*2; i++){
                if(x==0 and y==0) break;
                dir %= 4;
                // Sleep(500);
                x += ux[dir];
                y += uy[dir];
                moveSand(x,y,dir);
            }
            dir++;
        }
        count++;
    }
    cout << ans;
}