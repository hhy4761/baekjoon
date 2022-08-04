#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1000001];
int w[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[2] = 1;
    w[2] = 1;
    for(int i=3; i<=n; i++){
        int a = INT32_MAX,b=INT32_MAX;
        if(i % 3 == 0)
            a = d[i/3];
        if(i%2 ==0)
            b = d[i/2];
        d[i] = min({a,b,d[i-1]}) + 1;
        if(d[i] == a+1) w[i] = i/3;
        else if(d[i] == b+1) w[i] = i/2;
        else if(d[i] == d[i-1]+1) w[i] = i-1;
    }
    cout << d[n] << "\n";
    
    cout << n << ' ';
    while(n!=1){
        cout << w[n] << ' ';
        n = w[n];
    }
}