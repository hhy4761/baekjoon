#include <iostream>
#include <numeric>
using namespace std;

int n;
long long d[1001][10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(d[1],d[2],1);
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            d[i][j] = accumulate(d[i-1]+j,d[i-1]+10,0)%10007;
        }
    }
    cout << accumulate(d[n],d[n]+10,0) % 10007;
}