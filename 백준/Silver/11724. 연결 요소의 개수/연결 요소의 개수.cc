#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n,m,ans;
bool visited[1001];
unordered_map<int,vector<int>> graph;

void dfs(int cur){
    vector<int> stack;
    stack.push_back(cur);
    while(!stack.empty()){
        cur = stack.back(); stack.pop_back();
        for(auto v : graph[cur]){
            if(!visited[v]){
                visited[v] = true;
                stack.push_back(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        else{
            visited[i] = true;
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}