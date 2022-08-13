#include <bits/stdc++.h>
using namespace std;

int tc,n,m;
int coin[20];
int cache[10000][20];
int solve(int totalV,int cur){
    if(totalV >= m) return totalV == m;
    int& ret = cache[totalV][cur];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=cur; i<n; i++){
        ret += solve(totalV+coin[i],i);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> coin[i];
        cin >> m;
        fill(cache[0],cache[10000],-1);
        cout << solve(0,0);
        cout << "\n";
    }
}