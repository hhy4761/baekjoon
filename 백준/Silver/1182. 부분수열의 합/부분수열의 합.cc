#include <iostream>

using namespace std;
int n,k;
int cnt = 0;
int nums[20];

void func(int cur,int tot){
    if(cur==n) {
        if(tot==k) cnt++;
        return;
    }
    func(cur+1,tot);
    func(cur+1,tot+nums[cur]);
}
int main(){
    cin >> n >> k;
    for(int i=0; i<n;i++) cin >> nums[i];

    func(0,0);
    if(k==0) cnt--;
    cout << cnt;
}