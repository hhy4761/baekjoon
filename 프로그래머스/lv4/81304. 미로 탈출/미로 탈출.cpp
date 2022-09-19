#include <bits/stdc++.h>
using namespace std;

int inf = INT32_MAX;
int graph[1010][1010];
bool visited[1010][1030];
struct cmp{
    bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b){
        int x1,x2,x3,y1,y2,y3;
        tie(x1,x2,x3) = a;
        tie(y1,y2,y3) = b;
        return x1>y1;
    }
};
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    /*    1 2 3 4
        1 0 1   
        2   0   1
        3   1 0 
        4       0
    */
    // 그래프 초기화 => 자기자신은 0 나머지는 inf
    fill(graph[0],graph[1010],inf);
    for(int i=1; i<=n; i++){
        graph[i][i] = 0;
    }
    
    // 간선 반영
    for(auto& e : roads){
        int u,v,w;
        u = e[0], v = e[1], w = e[2];
        
        // 최단경로만 선택할 것이기에 가중치값이 높은 간선을 선택할 필요 x 
        if(w < graph[u][v]) graph[u][v] = w;
    }
    
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,cmp> pq;
    pq.push(make_tuple(0,start,0));
    
    while(!pq.empty()){
        int cost,node,state;
        tie(cost,node,state) = pq.top(); pq.pop();
        // 노드 방문 체크
        if(node == end) return cost;
        if(visited[node][state]) continue;
        visited[node][state] = true;
        
        // 현재 노드와 진행하려는 노드의 Trap의 발동 여부 체크
        bool curTrap = false;
        unordered_map<int,bool> curTraps;
        for(int i=0; i<traps.size(); i++){
            int bit = 1 << i;
            int s = state&bit;
            // 현재 state로 발동된 모든 trap 체크
            if(state & bit){
                // 현재 노드가 trap이고 발동된 상태라면 현재 노드번호의 trap을 꺼주어야함
                if(traps[i] == node) state &= ~bit;
                else curTraps[traps[i]] = true;
            }
            // 아직 발동되지 않은 trap이 현재 노드라면 켜주어야함
            else{
              if(traps[i] == node){
                state |= bit;
                curTraps[traps[i]] = true;
                curTrap = true;
                }  
            } 
        }
        // 인접노드로 이동. graph에서 해당 노드의 해당하는 행을 조사
        for(int v=1; v<=n; v++){
            // 자기자신
            if(node == v) continue; 
            
            // original 간선을 사용? reverse 간선을 사용?
            bool nextTrap = curTraps[v] ? true : false;
            // 현재 노드와 진행하고자 하는 노드 둘다 트랩이 발동했거나 안했다면 original 간선을 사용
            if(curTrap == nextTrap) {
                // 간선이 존재한다면 pq에 push
                if(graph[node][v] != inf) pq.push(make_tuple(cost+graph[node][v], v, state));
            }
            // 현재 노드와 진행하고자 하는 노드가 서로 상태가 다르다면 reverse 간선을 사용
            else{
                // 간선이 존재한다면 pq에 push
                if(graph[v][node] != inf) pq.push(make_tuple(cost+graph[v][node], v, state));
            }
        }
    }
    return inf;
}