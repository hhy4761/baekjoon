#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

string board[5];
bool mask[25];
int ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(mask,mask+7,true);
    sort(mask,mask+25);
    for(int i =0; i<5; i++)
        cin >> board[i];
    do{
        queue<pair<int,int>> q;
        bool isp7[5][5] = {};
        int adj=0, cnt=0;
        for(int i=0; i<25; i++){
            if(mask[i]){
                int x = i/5, y = i%5;
                isp7[x][y] = true;
                if(q.empty()){
                    q.push({x,y});
                    isp7[x][y] = false;
                }
            }
        }
        while(!q.empty()){
            int x,y;
            tie(x,y) = q.front(); q.pop();
            adj++;
            if(board[x][y] == 'S') cnt++;
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 or nx>=5 or ny<0 or ny>=5 or !isp7[nx][ny])
                    continue;
                isp7[nx][ny] = false;
                q.push({nx,ny});
            }
        }
        if(cnt>=4 and adj>=7) ans++;
    }while(next_permutation(mask,mask+25));
    cout << ans;
}