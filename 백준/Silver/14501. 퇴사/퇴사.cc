#include <iostream>
#include <algorithm>
using namespace std;

int n;
int time[17],price[17],d[17];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int t,p;
        cin >> t >> p;
        time[i] = t;
        price[i] = p;
    }
    for(int i=1; i<=n+1; i++){
        for(int j=1; j<=i; j++){
            if(time[j]+j < i+1){
                d[i] = max(d[i],d[j]+price[j]);
            }
        }
    }
    cout << d[n+1];
}