#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int n;
int s[8],w[8];
int ans = 0;
int cnt = 0;

void solve(int cur){
    if(cur == n){
        ans = max(ans,cnt);
        return;
    }
    if(s[cur] <= 0 or cnt == n-1){
        solve(cur+1);
        return;
    }
    for(int i=0; i<n; i++){
        if(s[i]<=0 or cur==i) continue;
        s[cur] -= w[i];
        s[i] -=w[cur];
        if(s[cur] <= 0) cnt++;
        if(s[i] <= 0) cnt++;
        solve(cur+1);
        if(s[cur] <=0) cnt--;
        if(s[i] <=0) cnt--;
        s[cur] += w[i];
        s[i] += w[cur];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i] >> w[i];
    }
    solve(0);
    cout << ans;
}