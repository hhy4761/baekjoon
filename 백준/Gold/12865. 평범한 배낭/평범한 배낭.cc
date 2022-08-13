#include <bits/stdc++.h>
using namespace std;

int n,k;
int w[101];
int v[101];
int cache[100001][101];

int pack(int totalW, int cur){
    if(cur == n) return 0;
    int& ret = cache[totalW][cur];
    if(ret!= -1) return ret;
    ret = pack(totalW,cur+1);
    if(totalW+w[cur] <= k){
        ret = max(ret,pack(totalW+w[cur],cur+1)+v[cur]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> w[i];
        cin >> v[i];
    }
    fill(cache[0],cache[100000],-1);
    cout << pack(0,0);
}