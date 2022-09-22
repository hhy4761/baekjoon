#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct person{
    int sales;
    vector<int> team;
};
vector<int> Sales;
vector<person> people(300005);
int cost[300010][2];

void traversal(int cur){
    cost[cur][0] = 0; // cur가 참석하지 않았을 때
    cost[cur][1] = people[cur].sales;
    
    if(people[cur].team.empty()){ // leaf 노드일 때
        return;
    }
    int extraCost = INT32_MAX; 
    for(auto& child: people[cur].team){ // 자식노드 순회
        traversal(child); // 모든 노드에 대해서 참석하는 경우와 참석하지 않는 경우의 cost값 저장
        if(cost[child][0] < cost[child][1]){ // 작은 cost로 현재 노드 업데이트
            cost[cur][0] += cost[child][0];
            cost[cur][1] += cost[child][0];
            extraCost = min(extraCost, cost[child][1] - cost[child][0]); // 부모가 선택되지 않으면 자식 중 한명이라도 선택해야하므로 그 중 가장 차이가 적은 cost 선택
        }
        else{ // 작은 cost로 현재 노드 업데이트
            cost[cur][0] += cost[child][1];
            cost[cur][1] += cost[child][1];
            extraCost = 0; // 자식을 골랐다면 추가적으로 드는 cost 없음
        }
    }
    cost[cur][0] += extraCost;
}
int solution(vector<int> sales, vector<vector<int>> links) {
    Sales = sales;
    for(auto&e : links){
        people[e[0]].sales = sales[e[0]-1];
        people[e[0]].team.push_back(e[1]);
        people[e[1]].sales = sales[e[1]-1];
    }
    
    // fill(cost[0],cost[300010],-1);
    traversal(1);
    return min(cost[1][0],cost[1][1]);
}