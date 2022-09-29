#include <bits/stdc++.h>
using namespace std;
int tc;
int sel[100005];
int visited[100005];
bool check[100005];
void dfs(int start){
    // cout << "start : " << start <<"\n";
    vector<int> stack;
    vector<int> cand;
    int cur,next;
    bool find=false;
    
    stack.push_back(start);
    check[start] = true;
    cand.push_back(start);
    while(!stack.empty()){
        cur = stack.back(); stack.pop_back();
        // cout << cur << "\n";
        next = sel[cur];
        if(visited[next] != -1){
            break;
        } 
        if(check[next]){
            find = true;
            break;
        } 
        check[next] = true;
        cand.push_back(next);
        stack.push_back(next);
    }
    // cout << "\n";
    if(find){
        while(cand.back() != next){
            visited[cand.back()] = 1;
            cand.pop_back();
        }
        visited[cand.back()] = 1; cand.pop_back();
    }
    while(!cand.empty()){
        visited[cand.back()] = 0;
        cand.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> tc;
    while(tc--){
        memset(visited,-1,sizeof(visited));
        memset(check,0,sizeof(check));
        int n, count = 0;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> sel[i];
            if(sel[i] == i) visited[i] = 1;
        } 
        for(int i=1; i<=n; i++){
            if(visited[i] != -1) continue;
            else if(visited[sel[i]] == 0 or visited[sel[i]] == 1) visited[i]=0;
            else dfs(i);
        } 
        // cout << "\n";
        for(int i=1; i<=n; i++){
            if(visited[i] == 0) count++;
        }
        cout << count << "\n";
    }

}
