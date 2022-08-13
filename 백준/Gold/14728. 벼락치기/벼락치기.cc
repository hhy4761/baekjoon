#include <bits/stdc++.h>
using namespace std;

int n,t;
int k[100];
int s[100];
int cache[10001][101];
int study(int totalT, int cur){
    if(cur == n) return 0;
    int& ret = cache[totalT][cur];
    if(ret != -1) return ret;
    ret = study(totalT,cur+1);
    if(totalT+k[cur] <= t){
        ret = max(ret,study(totalT+k[cur],cur+1)+s[cur]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> k[i];
        cin >> s[i];
    }
    fill(cache[0],cache[10001],-1);
    cout << study(0,0);

}