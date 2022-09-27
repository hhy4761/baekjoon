#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tc;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        vector<int> adj[1010];
        vector<int> rev[1010];
        queue<int> q;
        int T[1010] = {0};
        int deg[1010] = {0};
        int n,k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> T[i];
        for(int i=1; i<=k; i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b); // a를 짓고나서 b를 건설가능
            rev[b].push_back(a); // b를 짓는데 필요한 건물리스트 저장 for 가장 시간이 많이 든 건물 찾기 위해
            deg[b]++;
        }
        for(int i=1; i<=n; i++){
            if(deg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(auto& nxt : adj[cur]){
                deg[nxt]--;
                if(deg[nxt]==0){
                    int maxT = -1;
                    for(auto& e : rev[nxt]){
                        maxT = max(maxT,T[e]);
                    }
                    T[nxt] += maxT;
                    q.push(nxt);
                }
            }
        }
        int ans;
        cin >> ans;
        cout << T[ans] << "\n";
    }
}