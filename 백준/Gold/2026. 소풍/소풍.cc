#include <iostream>
#include <vector>
using namespace std;

int N,K,F;
vector<int> graph[904];
vector<int> cand;
int conn[904];
bool findCands;
void dfs(int curN){
    if(cand.size() == K){
        bool check = true;
        for(auto& e : cand){
            if(conn[e] < K-1){
                check = false;
                break;
            }
        }
        if(check){
            findCands = true;
            for(auto& e : cand) cout << e << "\n";
        } 
        return;
    }
    
    for(int i=curN; i<=N; i++){
        if(findCands) return; // 한번 찾으면 다음 탐색 할 필요 없음
        if(graph[i].size() < K-1) continue;
        else{
            cand.push_back(i);
            for(auto&e : graph[i]) conn[e]++;
            dfs(i+1);
            cand.pop_back();
            for(auto&e : graph[i]) conn[e]--;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N >> F;
    for(int i=0; i<F; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    if(!findCands) cout << -1;
}