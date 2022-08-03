#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int ans[10];
int nums[10];
void dfs(int cur,int start){
    if(cur==m){
        for(int i=0;i<m;i++)
            cout << ans[i] << ' ';
        cout << "\n";
        return;
    }
    int temp = -1;
    for(int i=start; i<n;i++){
        if(temp != nums[i]){
            ans[cur] = nums[i];
            temp = nums[i];
            dfs(cur+1, i+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n;i++)
        cin >> nums[i];
    sort(nums,nums+n);
    dfs(0,0);
}