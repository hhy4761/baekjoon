#include <iostream>

using namespace std;
int n,m;
int arr[10];
void dfs(int cur){
    if(cur==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        arr[cur] = i;
        dfs(cur+1);
    }
}
int main(){
    cin >> n >> m;
    dfs(0);
}