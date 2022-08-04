#include <iostream>
using namespace std;

int t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int d[11] = {};
        d[1] = 1;
        d[2] = 2;
        d[3] = 4;
        if(n>=4){
            for(int i=4; i<=n; i++){
                d[i] = d[i-3] + d[i-2] + d[i-1];
            }
        }
        cout << d[n] << "\n";
    }
}