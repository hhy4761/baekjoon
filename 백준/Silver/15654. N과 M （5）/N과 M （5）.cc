#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int> arr;
int ans[10];
bool used[10000];
void dfs(int cur){
    if(cur==m){
        for(int i=0; i<m;i++){
            cout << ans[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if(!used[arr[i]]){
            ans[cur] = arr[i];
            used[arr[i]] = 1;
            dfs(cur+1);
            used[arr[i]] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    dfs(0);
}
