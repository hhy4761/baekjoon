#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
int board[21][21];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
unordered_map<int,vector<int>> um;
pair<int,int> findCands(int cur){
    int maxLike = -1;
    int maxAdj = -1;
    pair<int,int> cand;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j]!=0) continue;
            int likeCount = 0;
            int adjCount = 0;
            for(int k=0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<1 or nx>n or ny<1 or ny>n) continue;
                if(find(um[cur].begin(),um[cur].end(),board[nx][ny]) != um[cur].end()) likeCount++;
                if(board[nx][ny] == 0) adjCount++;
            }
            if(maxLike < likeCount){
                maxLike = likeCount;
                maxAdj = adjCount;
                cand = {i,j};
            }
            else if(maxLike == likeCount and maxAdj < adjCount){
                maxAdj = adjCount;
                cand = {i,j};
            }
        }
    }
    return cand;
}

int checkTotal(){
    int total = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int cur = board[i][j];
            int cnt = 0;
            for(int k=0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<1 or nx>n or ny<1 or ny>n) continue;
                if(find(um[cur].begin(),um[cur].end(),board[nx][ny]) != um[cur].end()) cnt++;
            }
            if(cnt==1) total+=1;
            else if(cnt==2) total+=10;
            else if(cnt==3) total+=100;
            else if(cnt==4) total+=1000;
        }
    }
    return total;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n*n; i++){
        int student,a,b,c,d;
        cin >> student >> a >> b >> c >> d;
        um[student].push_back(a);
        um[student].push_back(b);
        um[student].push_back(c);
        um[student].push_back(d);
        pair<int,int> v = findCands(student);
        board[v.first][v.second] = student;
    }
    cout << checkTotal();
}