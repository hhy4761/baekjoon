#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> pd[1010];
vector<int> adj[1010];
queue<int> q;
int deg[1010];
vector<int> ans;
int n,m;
bool success = true;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int num,k;
        cin >> num;
        for(int j=0; j<num; j++){
            cin >> k;
            pd[i].push_back(k);
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<pd[i].size()-1; j++){
            adj[pd[i][j]].push_back(pd[i][j+1]);
            deg[pd[i][j+1]]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(deg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(auto& nxt: adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0){
                q.push(nxt);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(deg[i]!=0) {
            success = false;
            break;
        }
    }
    if(success){
        for(auto&e : ans) cout << e << "\n";
    }
    else cout << 0;
    
}