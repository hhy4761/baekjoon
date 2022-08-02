#include <iostream>

using namespace std;

int n,m;
int arr[10];
bool used[10];

void dfs(int cur){
    if(cur==m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(i < arr[cur-1] or used[i]) continue;
        arr[cur] = i;
        used[i] = 1;
        dfs(cur+1);
        used[i] =0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dfs(0);
}