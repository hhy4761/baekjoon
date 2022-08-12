#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int nums[1001];
int cache[1001][1001][2];

int bitonic(int curPos, int lastNum, bool isDec){
    if(curPos == n) return 0;
    int& ret = cache[curPos][lastNum][isDec];
    if(ret != -1) return ret;

    ret = 0;
    ret = bitonic(curPos+1,lastNum,isDec);
    if(!isDec){
        if(lastNum < nums[curPos])
            ret = max(ret,bitonic(curPos+1,nums[curPos],isDec)+1);
        else if(lastNum > nums[curPos])
            ret = max(ret,bitonic(curPos+1,nums[curPos],!isDec)+1);
    }
    else if(isDec and lastNum > nums[curPos]){
        ret = max(ret, bitonic(curPos+1,nums[curPos],isDec)+1);
    }
    return ret;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> nums[i];
    fill(cache[0][0],cache[1001][0],-1);
    cout << bitonic(0,0,false);
}