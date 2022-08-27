#include <iostream>
using namespace std;

int n,m;
int parent[201];
int plan[1001];
int find(int a){
    if(parent[a] == a) return a;
    parent[a] = find(parent[a]);
    return parent[a];
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(a < b) parent[b] = a;
    else parent[a] = b;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) parent[i] = i; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int num;
            cin >> num;
            if(num==1) merge(i,j);
        }
    }
    for(int i=0; i<m;i++){
        cin >> plan[i];
    }
    int root = find(plan[0]);
    for(int i=1; i<m; i++){
        if(root != find(plan[i])){
            cout <<"NO";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}