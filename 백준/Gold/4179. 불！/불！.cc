#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;
int r,c;
int human[1002][1002];
int fire[1002][1002];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
string board[1002];

int main(){
    cin >> r >> c;
    queue<pair<int,int>> jq;
    queue<pair<int,int>> fq;
    for(int i=0; i<r; i++)
        cin >> board[i];
    for(int i=0; i<r;i++){
        fill(human[i],human[i]+c,-1);
        fill(fire[i],fire[i]+c,-1);
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(board[i][j] == 'J'){
                jq.push({i,j});
                human[i][j] = 0;
            }
            else if(board[i][j] == 'F'){
                fq.push({i,j});
                fire[i][j] = 0;
            }
        }
       
    while(!fq.empty()){
        auto cur = fq.front(); fq.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 or nx>=r or ny<0 or ny >=c)
                continue;
            
            if(fire[nx][ny] >= 0 or board[nx][ny]=='#') 
                continue;
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            fq.push({nx,ny});
        }
    }
    while(!jq.empty()){
        auto cur = jq.front(); jq.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 or nx>=r or ny<0 or ny >=c){
                cout << human[cur.first][cur.second] + 1;
                return 0;
            }
            if(human[nx][ny]>=0 or board[nx][ny] == '#') 
                continue;
            if(fire[nx][ny] != -1 and fire[nx][ny] <= human[cur.first][cur.second] +1 )
                continue;
            human[nx][ny] = human[cur.first][cur.second] + 1;
            jq.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
}