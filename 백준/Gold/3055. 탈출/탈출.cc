#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int r,c;
string board[51]; 
int S[51][51];
int W[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct idx{
    int x,y;
};
idx idxS,idxW,idxD;
vector<idx> idxWs;
void bfsS(){
    queue<pair<int,int>> q;
    q.push({idxS.x,idxS.y});
    S[idxS.x][idxS.y] = 0;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front(); q.pop();
        
        for(int i=0;i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=r or ny<0 or ny >=c) continue;
            if(board[nx][ny]=='*' or board[nx][ny]=='X') continue;
            if(S[nx][ny] != -1 or (W[nx][ny] != -1 and W[nx][ny] <= S[x][y]+1)) continue;
            if(board[nx][ny]=='D'){
                S[nx][ny] = S[x][y] += 1;
                return;
            }
            S[nx][ny] = S[x][y] + 1;
            q.push({nx,ny});
        }
    }
}
void bfsW(){
    queue<pair<int,int>> q;

    for(auto& e: idxWs){
        q.push({e.x,e.y});
        W[e.x][e.y] = 0;
    }

    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front(); q.pop();
        
        for(int i=0;i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 or nx>=r or ny<0 or ny >=c) continue;
            if(board[nx][ny]=='D' or board[nx][ny]=='X') continue;
            if(W[nx][ny] != -1) continue;
            W[nx][ny] = W[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

void printArr(){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            cout << S[i][j] << " ";
        }
        cout << "\n";
    }    
}
void printArr2(){
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            cout << W[i][j] << " ";
        }
        cout << "\n";
    }    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0; i<r; i++){
        cin >> board[i];
        if(board[i].find("*")!=string::npos){
            for(int j=0; j<c; j++){
                if(board[i][j] == '*'){
                    idx idxW;
                    idxW.x = i, idxW.y =j;
                    idxWs.push_back(idxW);
                }
            }
        }
        if(board[i].find("S")!=string::npos){
            idxS.x = i, idxS.y = board[i].find("S");
        }
        if(board[i].find("D")!=string::npos){
            idxD.x = i, idxD.y = board[i].find("D");
        }
    }
    fill(S[0],S[51],-1);
    fill(W[0],W[51],-1);
    bfsW(); bfsS();
    // printArr();
    // cout <<"\n";
    // printArr2();
    int ans = S[idxD.x][idxD.y];
    if(ans != -1) cout << ans;
    else cout <<"KAKTUS";
}