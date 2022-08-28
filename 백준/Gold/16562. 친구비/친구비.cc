#include <iostream>
using namespace std;
int n,m,k,ans;
int friends[10005];
int parent[10005];
int find(int a){
    if(parent[a] == a) return a;
    parent[a] = find(parent[a]);
    return parent[a];
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(a > b){
        parent[a] = b;
        friends[b] = min(friends[a],friends[b]);
    }
    else{
        parent[b] = a;
        friends[a] = min(friends[a],friends[b]);
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=1; i<=n; i++){
        cin >> friends[i];
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        merge(a,b);
    }
    for(int i=1; i<=n; i++){
        if(find(i) == i){
            ans += friends[i];
        }
    }
    if(ans > k) cout <<"Oh no";
    else cout << ans;
}