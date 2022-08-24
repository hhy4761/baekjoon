#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int tc,v,e;
int visited[20001];
unordered_map<int,vector<int>> graph;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> v >> e;
        queue<int> q;
        bool res = true;
        fill(visited,visited+20001,-1);
        graph.clear();
        for(int i=0; i<e; i++){
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1; i<=v; i++){
            if(visited[i] == -1){
                q.push(i);
                visited[i] = 0;

                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    for(auto v : graph[cur]){
                        if(visited[v] == -1){
                            visited[v] = abs(visited[cur]-1);
                            q.push(v);
                        }
                        else if(visited[v] != -1 and visited[cur] == visited[v]){
                            res = false;
                            break;
                        }
                    }
                }
                if(!res) break;
            }
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
}