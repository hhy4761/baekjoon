#include <iostream>
using namespace std;

int n,m;
int nums[100001];
int d[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> nums[i];
    d[1] = nums[1];
    for(int i=2; i<=n; i++){
        d[i] = d[i-1] + nums[i];
    }
    while(m--){
        int i,j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << "\n";
    }
}