#include <iostream>
#include <algorithm>
using namespace std;

int n;
int r[1001];
int g[1001];
int b[1001];
int d[3][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> r[i] >> g[i] >> b[i];
    }
    d[0][1] = r[1]; 
    d[1][1] = g[1]; 
    d[2][1] = b[1];
    for(int i=2;i<=n;i++){
        d[0][i] = min(d[1][i-1],d[2][i-1]) + r[i];
        d[1][i] = min(d[0][i-1],d[2][i-1]) + g[i];
        d[2][i] = min(d[0][i-1],d[1][i-1]) + b[i];
    }
    cout << min({d[0][n],d[1][n],d[2][n]});
}