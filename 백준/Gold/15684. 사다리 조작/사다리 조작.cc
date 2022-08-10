#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m,h;
bool board[31][11];
int comb[500];

bool test(){
    for(int i=1; i<=n; i++){
        int cur = i;
        for(int j=1; j<=h; j++){
            if(board[j][cur]){
                cur++;
            } 
            else if(board[j][cur-1]){
                cur--;
            }
        }
        if(cur!=i) return false;
    }
    return true;
}

bool dfs(int st,int cur,int fin){
    if(cur==fin){
        return test();
    }
    for(int i=st; i<=(n-1)*h; i++){
        int x,y;
        x = i/(n-1) + 1; y = i%(n-1) + 1;
        if(board[x][y]==1) continue;
        if(board[x][y-1]==1) continue;
        if(board[x][y+1]==1) continue;
        board[x][y] = 1;
        if(dfs(i+1,cur+1,fin)) break;
        board[x][y] = 0;
    }
    return test();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h;
    while(m--){
        int a,b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    bool tmp = false;
    for(int i=0; i<=3; i++){
        if(dfs(0,0,i)){
            cout << i;
            tmp = true;
            break;
        }
    }
    if(!tmp) cout <<-1;
}