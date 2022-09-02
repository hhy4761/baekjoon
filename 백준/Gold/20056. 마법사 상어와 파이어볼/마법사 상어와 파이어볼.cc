#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k,ans;
struct fire{
    int m,s,d;
};
vector<fire> board[55][55]; // 파이어볼 개수 표시
vector<fire> temp[55][55]; // 임시 배열
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void moveFire(int r,int c,vector<fire> fires){
    for(auto& fire : fires){
        int stride = fire.s % n;
        int x = r, y = c;
        while(stride--){
            x += dx[fire.d];
            y += dy[fire.d];
            if(x > n) x = 1;
            if(x < 1) x = n;
            if(y > n) y = 1;
            if(y < 1) y = n;
        }
        temp[x][y].push_back(fire);
    }
    
}
int mergeFire(int r,int c,vector<fire>& fires){
    int sumM = 0;
    int sumS = 0;
    int isOdd = 0;
    int isEven = 0;
    int count = 0;
    int D;
    for(auto& fire : fires){
        count++;
        sumM += fire.m;
        sumS += fire.s;
        if(fire.d % 2==0) isEven++;
        else isOdd++;
    }
    fires.clear();
    // 모두 홀수거나 짝수
    if(isEven == 0 or isOdd == 0) D = 0;
    // 그 외
    else D = 1;
    fire f = {sumM,sumS,D};
    fires.push_back(f);
    return count;
}
void splitFire(int r,int c,int count){
    fire f = board[r][c].back(); board[r][c].clear();
    int newM = f.m/5;
    int newS = f.s/count;
    if(newM == 0) return;
    if(f.d == 0){
        for(int i=0; i<4; i++){
            fire f = {newM,newS,i*2};
            board[r][c].push_back(f);
        }
    }
    else{
        for(int i=0; i<4; i++){
            fire f = {newM,newS,i*2+1};
            board[r][c].push_back(f);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        fire f = {m,s,d};
        board[r][c].push_back(f);
    }
    while(k--){
        // 임시 배열 초기화
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                temp[i][j].clear();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(board[i][j].empty()) continue;
                moveFire(i,j,board[i][j]);
            }
        }

        copy(temp[1],temp[n+1],board[1]);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(board[i][j].size() >=2){
                    int num = mergeFire(i,j,board[i][j]);
                    splitFire(i,j,num);
                }
            }
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n; j++){
            if(board[i][j].empty()) continue;
            for(auto& fire : board[i][j]){
                ans += fire.m;
            }
        }
    }
    cout << ans;
}