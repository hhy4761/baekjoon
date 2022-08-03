#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int ans[10];
int nums[10];
void dfs(int cur){
    if(cur==m){
        for(int i=0;i<m;i++)
            cout << ans[i] << ' ';
        cout << "\n";
        return;
    }
    for(int i=0; i<n;i++){
        ans[cur] = nums[i];
        dfs(cur+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n;i++){
        int num;
        cin >> num;
        nums[i] = num;
    }
    sort(nums,nums+n);
    dfs(0);
}