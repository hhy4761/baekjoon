#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int n;
bool broken[8];
vector<pair<int,int>> v;
int ans=0;
void dfs(int cur, int cnt){
    if(cur == n){
        ans = max(ans, cnt);
        return;
    }
    int cur_d,cur_w;
    tie(cur_d,cur_w) = v[cur];
    if(broken[cur]) dfs(cur+1,cnt);
    else{
        bool inloop = false;
        for(int j=0; j<n; j++){
            if(cur==j or broken[j]) continue;
            inloop = true;
            int next_d,next_w;
            tie(next_d,next_w) = v[j];
            v[cur] = {cur_d-next_w,cur_w};
            v[j] = {next_d-cur_w,next_w};
            if(v[cur].first <= 0){
                broken[cur] = 1;
                cnt++;
            } 
            if(v[j].first <= 0){
                broken[j] = 1;
                cnt++;
            } 
            dfs(cur+1, cnt);
            v[cur] = {v[cur].first+next_w,cur_w};
            v[j] = {v[j].first+cur_w,next_w};
            if(broken[cur]){
                broken[cur] = 0;
                cnt--;
            } 
            if(broken[j]){
                broken[j] = 0;
                cnt--;
            } 
        }
        if(!inloop) dfs(cur+1,cnt);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int durability, weight;
        cin >> durability >> weight;
        v.push_back({durability,weight});
    }
    dfs(0,0);
    cout << ans;
}