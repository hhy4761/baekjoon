#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
long long t[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> t[i];
    sort(t,t+n);
    long long left = 0, right = t[n-1] * m;
    long long ans = right;
    while(left <= right){
        long long total = 0;
        long long mid = (left+right) / 2;

        for(int i=0; i<n; i++){
            total += (mid/t[i]);
        }

        if(total < m) left = mid+1;
        else{
            right = mid-1;
            ans = min(ans,mid);
        }
    }
    cout << ans;
    return 0;
    
}