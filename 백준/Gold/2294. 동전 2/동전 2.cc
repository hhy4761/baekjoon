#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int d[100001];
int coin[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(d,d+100001,-1);

    for(int i=1; i<=n; i++){
        cin >> coin[i];
        d[coin[i]] = 1;
    }
    
    for(int i=1; i<=k; i++){
        if(d[i] != -1) continue;
        for(int j=1; j<=n; j++){
            if(i > coin[j] and d[i-coin[j]] != -1){
                if(d[i] == -1) d[i] = d[i-coin[j]]+1;
                d[i] = min(d[i],d[i-coin[j]]+1);
            }
        }
    }
    // for(int i=1; i<=k; i++) cout << d[i] << ' ';
    cout << d[k];
}