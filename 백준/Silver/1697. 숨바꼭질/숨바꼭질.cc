#include <iostream>
#include <queue>

using namespace std;
int vis[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(auto &num : vis) num = INT32_MAX;
    queue<pair<int,int>> q;
    q.push({n,0});
    vis[n] = 0;
    int count = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cur_x = cur.first;
        int count = cur.second;
        for(auto c : {cur_x-1,cur_x+1,cur_x*2}){
            if(c<0 or c>100000 or vis[c] < count+1) continue;
            q.push({c,count+1});
            vis[c] = count+1;
        }
    }
    cout << vis[k];
}