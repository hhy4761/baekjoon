#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int n,m;
priority_queue<int> pq;
vector<int> adj[32003];
int deg[32003];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    for(int i=1;i<=n; i++){
        if(deg[i] ==0) pq.push(-i);
    }
    while(!pq.empty()){
        int cur = -pq.top(); pq.pop();
        cout << cur << " ";
        for(auto& nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0) pq.push(-nxt);
        }
    }
}