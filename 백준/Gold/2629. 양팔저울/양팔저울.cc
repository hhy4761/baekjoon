#include <iostream>
using namespace std;
int n,m;
int weight[35];
int marble[10];
int dp[35][40005];
void check(int cur, int totalW){
    if(cur>n) return;
    if(dp[cur][totalW]!=-1) return;

    dp[cur][totalW] = 1;
    check(cur+1,totalW+weight[cur]);
    check(cur+1,abs(totalW-weight[cur]));
    check(cur+1,totalW);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> weight[i];
    cin >> m;
    for(int i=0;i<m;i++) cin >> marble[i];
    fill(dp[0],dp[35],-1);
    check(0,0);

    for(int i=0; i<m; i++){
        bool find = false;
        for(int j=0; j<=n; j++){
            if(dp[j][marble[i]]==1){
                find = true;
                break;
            }
        }
        if(find) cout << "Y ";
        else cout << "N ";
    }
}