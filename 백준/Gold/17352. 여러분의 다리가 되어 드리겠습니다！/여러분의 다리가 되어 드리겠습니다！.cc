#include <iostream>
#include <unordered_set>
using namespace std;

int n;
int parent[300005];

int find(int a){
    if(parent[a] == a) return a;
    parent[a] = find(parent[a]);
    return parent[a];
}

bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(a<b) parent[b] = a;
    else parent[a] =b;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<n-2; i++){
        int a,b;
        cin >> a >>b;
        merge(a,b);
    }
    // for(int i=1;i<=n;i++) cout << parent[i] <<" ";
    unordered_set<int> us;
    for(int i=1; i<=n; i++){
        us.insert(find(i));
    }
    for(auto& e:us) cout << e << " ";
}