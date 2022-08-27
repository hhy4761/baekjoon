#include <iostream>
using namespace std;
int n,m;
int parent[1000001];
int find(int a){
    if(parent[a] == a) return a;
    parent[a] = find(parent[a]);
    return parent[a];
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(a<b) parent[b] = a;
    else parent[a] = b;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++){
        int op,a,b;
        cin >> op >> a >> b;
        if(op==0){
            merge(a,b);
        }
        else{ // op==1
            if(find(a) != find(b)) cout <<"NO\n";
            else cout << "YES\n";
        }
    }
}