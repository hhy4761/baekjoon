#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long li[5050];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> li[i];
    sort(li,li+n);
    int left, right, mid, res[3];
    long long total, ans = INT64_MAX;
    for(int i=0; i<n-2; i++){
        left = i+1; right = n-1;
        while(left < right){
            // cout << i << " " << left << " " << right << "\n";
            total = li[i] + li[left] + li[right];
            // cout << abs(total) << " " << abs(ans) << "\n";
            if(abs(total) < abs(ans)){
                ans = total;
                res[0] = li[i];
                res[1] = li[left];
                res[2] = li[right];
            }
            if(total > 0){
                right--;
            }
            else if(total == 0){
                i = n;
                break;
            }
            else{
                left++;
            }
        }
    }
    cout << res[0] << " " << res[1] << " " << res[2];
}