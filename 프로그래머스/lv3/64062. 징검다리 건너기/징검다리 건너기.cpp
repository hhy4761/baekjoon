#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> S, int numFriends, int k){
    for(int i=0; i<S.size(); i++)
        S[i] -= numFriends;
    
    int emptyCount = 0;
    for(int i=0; i<S.size(); i++){
        if(emptyCount >= k) return false;
        if(S[i]<=0) emptyCount++;
        else emptyCount = 0;
    }
    return true;
}
int ans;
int solution(vector<int> stones, int k) {
    int start = 0, end = 200000000;
    while(start <= end){
        int mid = (start+end)/2;
        int emptyCount = 0;
        for(auto& s : stones){
            if(emptyCount >= k) break;
            if(s-mid <= 0) emptyCount++;
            else emptyCount = 0;
        }
        
        if(emptyCount >= k){ // 징검다리 건넌 친구들 수 감소시켜야함.
            end = mid - 1;
            ans = mid;
        }
        else{ // 징검다리 건넌 친구들 수 증가시켜야함.
            start = mid + 1;
        }
    }
    return ans;
}