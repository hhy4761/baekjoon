#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[505];
vector<int> rev[505];
queue<int> q;
int deg[505];
int times[505];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n ;i++){
        int t;
        cin >> t;
        times[i] = t;
        while(true){
            int num;
            cin >> num;
            if(num == -1) break;
            adj[num].push_back(i);
            rev[i].push_back(num);
            deg[i]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(auto& nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0){
                int maxT = -1;
                for(int i=0; i<rev[nxt].size(); i++){
                    maxT = max(maxT,times[rev[nxt][i]]);
                }
                times[nxt] += maxT;
                q.push(nxt);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << times[i] << "\n";
    }
}