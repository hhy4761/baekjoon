#include <iostream>
#include <cmath>
using namespace std;
int n;
int d[200000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=333; i++) d[(int)round(pow(i,2))] = 1;
    for(int i=1; i<=100000; i++){
        if(d[i]!=0) continue;
        for(int j=1; j < i; j++){
            int pow_num = (int)round(pow(j,2));
            if(i < pow_num) break;
            if(d[i]==0) d[i] = d[i-pow_num];
            d[i] = min(d[i],d[i-pow_num]);
        }
        d[i]++;
    }
    cout << d[n];
}