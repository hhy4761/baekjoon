#include <iostream>
#include <string>
#include <tuple>
#include <queue>
// #include <windows.h>
using namespace std;

int n,m;
string board[10];
bool pass_r,pass_b;

bool isFinish(int x, int y){
    if(board[x][y] == 'O') return true;
    return false;
}

tuple<int,int,int,int> up(tuple<int,int,int,int> pos){
    int x_r,y_r,x_b,y_b;
    tie(x_r,y_r,x_b,y_b) = pos;
    if(y_r == y_b){ // 같은 열에 위치
        if(x_r > x_b){ // 빨간색이 아래있다면 파란색 먼저 이동
            while((x_b > 0 and board[x_b-1][y_b] == '.') or board[x_b-1][y_b] =='O') {
                x_b--;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
            while((x_r > 0 and board[x_r-1][y_r] == '.' and x_r-1 != x_b) or board[x_r-1][y_r] =='O') {
                x_r--;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
        }
        else{ // 빨간색 먼저 이동
            while((x_r > 0 and board[x_r-1][y_r] == '.') or board[x_r-1][y_r] =='O') {
                x_r--;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
            while((x_b > 0 and board[x_b-1][y_b] == '.' and x_b-1 != x_r) or board[x_b-1][y_b] =='O') {
                x_b--;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
        }
    }
    else{ // 독립적으로 이동
        while((x_r > 0 and board[x_r-1][y_r] == '.') or board[x_r-1][y_r] == 'O') {
            x_r--;
            if(isFinish(x_r,y_r)) pass_r = true;
        }
        while((x_b > 0 and board[x_b-1][y_b] == '.') or board[x_b-1][y_b] =='O') {
            x_b--;
            if(isFinish(x_b,y_b)) pass_b = true;
        }
    }
    return make_tuple(x_r,y_r,x_b,y_b);
}
tuple<int,int,int,int> down(tuple<int,int,int,int> pos){
    int x_r,y_r,x_b,y_b;
    tie(x_r,y_r,x_b,y_b) = pos;
    if(y_r == y_b){ // 같은 열에 위치
        if(x_r > x_b){ // 빨간색이 아래있다면 빨간색 먼저 이동
            while(x_r < n and board[x_r+1][y_r] == '.' or board[x_r+1][y_r] =='O') {
                x_r++;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
            while((x_b < n and board[x_b+1][y_b] == '.' and x_b+1 != x_r)or board[x_b+1][y_b] =='O') {
                x_b++;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
        }
        else{ // 파란색 먼저 이동
            while(x_b < n and board[x_b+1][y_b] == '.' or board[x_b+1][y_b] =='O') {
                x_b++;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
            while((x_r < n and board[x_r+1][y_r] == '.' and x_r+1 != x_b) or board[x_r+1][y_r] =='O') {
                x_r++;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
        }
    }
    else{ // 독립적으로 이동
        while(x_r < n and board[x_r+1][y_r] == '.' or board[x_r+1][y_r] =='O') {
            x_r++;
            if(isFinish(x_r,y_r)) pass_r = true;
        }
        while(x_b < n and board[x_b+1][y_b] == '.' or board[x_b+1][y_b] =='O') {
            x_b++;
            if(isFinish(x_b,y_b)) pass_b = true;
        }
    }
    return make_tuple(x_r,y_r,x_b,y_b);
}
tuple<int,int,int,int> left(tuple<int,int,int,int> pos){
    int x_r,y_r,x_b,y_b;
    tie(x_r,y_r,x_b,y_b) = pos;
    if(x_r == x_b){ // 같은 행에 위치
        if(y_r < y_b){ // 빨간색이 왼쪽에 있다면 빨간색 먼저 이동
            while(y_r > 0 and board[x_r][y_r-1] == '.' or board[x_r][y_r-1] =='O') {
                y_r--;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
            while((y_b > 0 and board[x_b][y_b-1] == '.' and y_b-1 != y_r)or board[x_b][y_b-1] =='O') {
                y_b--;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
        }
        else{ // 파란색 먼저 이동
            while(y_b > 0 and board[x_b][y_b-1] == '.' or board[x_b][y_b-1] =='O') {
                y_b--;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
            while((y_r > 0 and board[x_r][y_r-1] == '.' and y_r-1 != y_b)or board[x_r][y_r-1] =='O') {
                y_r--;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
        }
    }
    else{ // 독립적으로 이동
        while(y_b > 0 and board[x_b][y_b-1] == '.' or board[x_b][y_b-1] =='O') {
                y_b--;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
            while(y_r > 0 and board[x_r][y_r-1] == '.' or board[x_r][y_r-1] =='O') {
                y_r--;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
    }
    return make_tuple(x_r,y_r,x_b,y_b);
}

tuple<int,int,int,int> right(tuple<int,int,int,int> pos){
    int x_r,y_r,x_b,y_b;
    tie(x_r,y_r,x_b,y_b) = pos;
    if(x_r == x_b){ // 같은 행에 위치
        if(y_r < y_b){ // 빨간색이 왼쪽에 있다면 파란색 먼저 이동
            while((y_b < m and board[x_b][y_b+1] == '.') or board[x_b][y_b+1] =='O') {
                y_b++;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
            while((y_r < m and board[x_r][y_r+1] == '.' and y_r+1 != y_b) or board[x_r][y_r+1] =='O') {
                y_r++;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
        }
        else{ // 빨간색 먼저 이동
            while(y_r < m and board[x_r][y_r+1] == '.' or board[x_r][y_r+1] =='O') {
                y_r++;
                if(isFinish(x_r,y_r)) pass_r = true;
            }
            while((y_b < m and board[x_b][y_b+1] == '.' and y_b+1 != y_r)or board[x_b][y_b+1] =='O') {
                y_b++;
                if(isFinish(x_b,y_b)) pass_b = true;
            }
        }
    }
    else{ // 독립적으로 이동
        while(y_r < m and board[x_r][y_r+1] == '.' or board[x_r][y_r+1] =='O') {
            y_r++;
            if(isFinish(x_r,y_r)) pass_r = true;
        }
        while(y_b < m and board[x_b][y_b+1] == '.' or board[x_b][y_b+1] =='O') {
            y_b++;
            if(isFinish(x_b,y_b)) pass_b = true;
        }
    }
    return make_tuple(x_r,y_r,x_b,y_b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x_r,y_r,x_b,y_b;
    for(int i=0; i<n; i++){
        cin >> board[i];
        if(board[i].find("R") != string::npos){
            x_r = i;
            y_r = board[i].find("R");
            board[x_r][y_r] = '.';
        }
        if(board[i].find("B") != string::npos){
            x_b = i;
            y_b = board[i].find("B");
            board[x_b][y_b] = '.';
        }
    }

    queue<tuple<int,int,int,int,int>> q;
    q.push(make_tuple(x_r,y_r,x_b,y_b,0));
    while(!q.empty()){
        int count;
        int new_X_R,new_Y_R,new_X_B,new_Y_B;
        tie(x_r,y_r,x_b,y_b,count) = q.front(); q.pop();
        // cout << x_r << ' ' << y_r << ' ' << x_b << ' ' << y_b << "\n";
        if(count >= 10) {
            cout << -1;
            break;
        }
        // cout << "count:" << count <<"\n";
        tie(new_X_R,new_Y_R,new_X_B,new_Y_B) = up(make_tuple(x_r,y_r,x_b,y_b));
        if(pass_r and !pass_b){
            cout << count+1;
            break;
        } 
        else if(pass_b){
            pass_r = false;
            pass_b = false;
        }
        else{
            q.push(make_tuple(new_X_R,new_Y_R,new_X_B,new_Y_B,count+1));
        }
        tie(new_X_R,new_Y_R,new_X_B,new_Y_B) = down(make_tuple(x_r,y_r,x_b,y_b));
        if(pass_r and !pass_b){
            cout << count+1;
            break;
        } 
        else if(pass_b){
            pass_r = false;
            pass_b = false;
        }
        else{
            q.push(make_tuple(new_X_R,new_Y_R,new_X_B,new_Y_B,count+1));
        }
        tie(new_X_R,new_Y_R,new_X_B,new_Y_B) = left(make_tuple(x_r,y_r,x_b,y_b));
        if(pass_r and !pass_b){
            cout << count+1;
            break;
        } 
        else if(pass_b){
            pass_r = false;
            pass_b = false;
        }
        else{
            q.push(make_tuple(new_X_R,new_Y_R,new_X_B,new_Y_B,count+1));
        }
        tie(new_X_R,new_Y_R,new_X_B,new_Y_B) = right(make_tuple(x_r,y_r,x_b,y_b));
        if(pass_r and !pass_b){
            cout << count+1;
            break;
        } 
        else if(pass_b){
            pass_r = false;
            pass_b = false;
        }
        else{
            q.push(make_tuple(new_X_R,new_Y_R,new_X_B,new_Y_B,count+1));
        }
    }
}