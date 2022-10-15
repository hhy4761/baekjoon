#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <cmath>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,k,ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<int> board[103];

void push_fish(){
    int min_val = 100000;
    vector<int> cands;
    for(int i=1; i<=n; i++){
        if(board[i].front() < min_val){
            min_val = board[i].front();
            cands.clear();
            cands.push_back(i);
        }
        else if(board[i].front() == min_val) cands.push_back(i);
    }
    for(auto& cand: cands){
        board[cand].front()++;
    }
}

void stacking(){
    double cnt = 0;
    int h;
    while(true){
        cnt++;
        h = (cnt/2) + 1;
        for(int i=1; i<=n; i++){
            int rotate_length = ceil(cnt/2);
            int rest = n - (i + rotate_length - 1);

            if(board[i].size() == 0) continue;
            if(h > rest) return;

            for(int j=i+rotate_length-1; j >= i; j--){
                for(int k=0; k<h; k++){
                    board[i+rotate_length+k].push(board[j].front());
                    board[j].pop();
                }
            }
            break;
        }
    }
}

void adjust(){
    int copy_board[103][103];
    int copy_board2[103][103];
    fill(copy_board[0],copy_board[103],0);
    fill(copy_board2[0],copy_board2[103],0);
    int cnt = 0;
    int col = 0;
    for(int i=1; i<=n; i++){
        if(board[i].empty()) continue;
        int j = 0;
        while(!board[i].empty()){
            copy_board[cnt][j] = board[i].front();
            board[i].pop();
            j++;
        }
        cnt++;
        col = max(col,j);
    }

    bool visited[cnt][col];
    fill(visited[0],visited[cnt],false);
    for(int i=0; i<cnt; i++){
        for(int j=0; j<col; j++){
            if(copy_board[i][j] == 0) continue;
            visited[i][j] = true;
            for(int k=0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx < 0 or nx >= cnt or ny < 0 or ny >= col) continue;
                if(visited[nx][ny]) continue;
                if(copy_board[nx][ny] == 0) continue;
                int diff = (abs(copy_board[i][j] - copy_board[nx][ny])) / 5;
                if(diff > 0){
                    if(copy_board[i][j] > copy_board[nx][ny]){
                        copy_board2[i][j] -= diff;
                        copy_board2[nx][ny] += diff;
                    }
                    else{
                        copy_board2[i][j] += diff;
                        copy_board2[nx][ny] -= diff;
                    }
                }
            }
        }
    }
    for(int i=0; i<=cnt; i++){
        for(int j=0; j<=col; j++){
            copy_board[i][j] += copy_board2[i][j];
        }
    }

    int cur = 1;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<col; j++){
            if(copy_board[i][j]>0){
                while(!board[cur].empty()) board[cur].pop();
                board[cur].push(copy_board[i][j]);
                cur++;
            }
        }
    }
}

void divide_twice(){
    int idx = n/2+1;
    for(int i = n/2; i>=1; i--){
        int cur = board[i].front();
        board[i].pop();
        board[idx].push(cur);
        idx++;
    }
    deque<int> dq;
    idx = n;
    for(int i=n/2+1; i<=n/2+n/4; i++){
        while(!board[i].empty()){
            dq.push_back(board[i].front());
            board[i].pop();
        }
        while(!dq.empty()){
            board[idx].push(dq.back());
            dq.pop_back();
        }
        idx--;
    }
}

bool check_k(){
    int max_val = -1;
    int min_val = INT32_MAX;
    for(int i=1; i<=n; i++){
        int cur = board[i].front();
        max_val = max(max_val, cur);
        min_val = min(min_val, cur);
    }
    if((max_val - min_val) <= k) return true;
    return false; 
}

void print(){
    // for(int i=1; i<=n; i++) cout << board[i].size() << " ";
    for(int i=1; i<=n; i++){
        if(board[i].empty()) continue;
        while(!board[i].empty()){
            cout << board[i].front() << " ";
            board[i].pop();
        }
        cout << "\n";
    }
    cout <<"\n";
}

int main(){
    fastio
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        int num;
        cin >> num;   
        board[i].push(num);
    }
    while(!check_k()){
        push_fish();
        stacking();
        adjust();
        divide_twice();
        adjust();
        ans++;
    }
    cout << ans;
}