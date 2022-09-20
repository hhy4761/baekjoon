#include <iostream>
using namespace std;

int n,m;
int parent[500003];
int find(int a){
    if(parent[a] == a) return a;
    parent[a] = find(parent[a]);
    return parent[a];
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(a < b) parent[b] = a;
    else parent[a] = b;
    return true;
}
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<=n; i++) parent[i] = i;
    bool isFirst = true;

    for(int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;
        bool res = merge(a,b);
        if(!res and isFirst){ // 이미 같은 부모를 가짐
            ans = i;
            isFirst = false;
        }
        else{ // 
            continue;
        }
    }
    cout << ans;
}