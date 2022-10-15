#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int r,c,k,w,ans;
int board[22][22];
bool visited[22][22];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
vector<pair<int,int>> thermometer;
vector<tuple<int,int,int>> circulator;
unordered_map<int,vector<int>> walls;

bool check_temperature(){
    for(auto& e : thermometer){
        if(board[e.first][e.second] < k) return false;
    }
    return true;
}

bool check_wall(int x, int y, int nx, int ny){
    if(find(walls[x*100+y].begin(),walls[x*100+y].end(),nx*100+ny) != walls[x*100+y].end()) return true;
    return false;
}

void spread(int cur, int x, int y, int dir){
    if(cur==5) return;

    int nx,ny;
    if(dir==1){ // 오른쪽
        nx = x-1; ny = y; 
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            ny++; 
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x-1,y,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        }

        nx = x+dx[dir], ny = y+dy[dir];
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            if(!visited[nx][ny]){
                board[nx][ny] += (5-cur);
                visited[nx][ny] = true;
                spread(cur+1, nx, ny, dir);
            }
        }

        nx = x+1; ny = y;
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            ny++;
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x+1,y,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        } 
    }
    else if(dir==2){ // 왼쪽
        nx = x-1; ny = y;
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            ny--;
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x-1,y,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        }

        nx = x+dx[dir], ny = y+dy[dir];
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            if(!visited[nx][ny]){
                board[nx][ny] += (5-cur);
                visited[nx][ny] = true;
                spread(cur+1, nx, ny, dir);
            }
        }

        nx = x+1; ny = y;
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            ny--;
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x+1,y,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        } 
    }
    else if(dir==3){ // 위쪽
        nx = x; ny = y-1;
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            nx--;
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y-1,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        }

        nx = x+dx[dir], ny = y+dy[dir];
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            if(!visited[nx][ny]){
                board[nx][ny] += (5-cur);
                visited[nx][ny] = true;
                spread(cur+1, nx, ny, dir);
            }
        }

        nx = x; ny = y+1;
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            nx--;
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y+1,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        } 
    }
    else{ // 아래쪽
        nx = x; ny = y-1;
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            nx++;
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y-1,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        }

        nx = x+dx[dir], ny = y+dy[dir];
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            if(!visited[nx][ny]){
                board[nx][ny] += (5-cur);
                visited[nx][ny] = true;
                spread(cur+1, nx, ny, dir);
            }
        }

        nx = x; ny = y+1;
        if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y,nx,ny)){
            nx++;
            if(!(nx < 1 or nx > r or ny < 1 or ny > c) and !check_wall(x,y+1,nx,ny)){
                if(!visited[nx][ny]){
                    board[nx][ny] += (5-cur);
                    visited[nx][ny] = true;
                    spread(cur+1, nx, ny, dir);
                }
            }
        } 
    }
}

void circulate(){
    for(auto& e : circulator){
        int x,y,num;
        tie(x,y,num) = e;
        int nx = x+dx[num];
        int ny = y+dy[num];
        board[nx][ny] += 5;
        fill(visited[0],visited[22],false);
        spread(1,nx,ny,num);
    }
}

void adjust(){
    int copy_board[22][22];
    bool visited2[22][22];
    fill(copy_board[0],copy_board[22],0);
    fill(visited2[0],visited2[22],0);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            visited2[i][j] = true;
            for(int k=1; k<=4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<1 or nx>r or ny<1 or ny>c) continue;
                if(visited2[nx][ny]) continue;
                if(check_wall(i,j,nx,ny)) continue;
                int diff = (abs(board[nx][ny] - board[i][j])) / 4;
                if(diff > 0){
                    if(board[nx][ny] > board[i][j]){
                        copy_board[nx][ny] -= diff;
                        copy_board[i][j] += diff;
                    }
                    else{
                        copy_board[nx][ny] += diff;
                        copy_board[i][j] -= diff;
                    }
                }
            }
        }
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            board[i][j] += copy_board[i][j];
        }
    }
}

void minus_one(){
    for(int i=1; i<=r; i++){
        if(i==1 or i==r){
            for(int j=1; j<=c; j++){
                if(board[i][j] > 0) board[i][j]--;
            }
        }
        else{
            if(board[i][1] > 0) board[i][1]--;
            if(board[i][c] > 0) board[i][c]--;
        }
    }
}

void print(){
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cout << board[i][j] << " ";
        }
         cout << "\n";
    }
}

int main(){
    fastio
    cin >> r >> c >> k;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            int num;
            cin >> num;
            if(1<= num and num <=4) circulator.push_back(make_tuple(i,j,num));
            else if(num == 5) thermometer.push_back({i,j});
        }
    }
    cin >> w;
    for(int i=1; i<=w; i++){
        int x,y,t;
        cin >> x >> y >> t;
        if(t==0){
            walls[x*100+y].push_back((x-1)*100 + y);
            walls[(x-1)*100+y].push_back(x*100 + y);
        }
        else{
            walls[x*100+y].push_back(x*100 + (y+1));
            walls[x*100+(y+1)].push_back(x*100 + y);
        } 
    }

    while(!check_temperature() and ans <= 100){
        ans++;
        circulate();
        adjust();
        minus_one();
    }
    // print();
    cout << ans;
}