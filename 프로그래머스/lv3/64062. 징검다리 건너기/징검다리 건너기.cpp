#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/* 
    통과할 수 없으면 F 가능하면 T 
    이분 탐색 시 T~~~F 범위를 가지게 됨
*/
bool check(vector<int> S, int numFriends, int k){
    int emptyCount = 0;
    for(auto& s : S){
        if(s-(numFriends) <= 0) emptyCount++;
        else emptyCount = 0;
        
        if(emptyCount >= k) return false;
    }
    return true;
}
int ans;
int solution(vector<int> stones, int k) {
    
    int start = 1;
    int end = *max_element(stones.begin(),stones.end());
    int mid;
    
    while(start+1 < end){
        mid = (start+end)/2;
        
        if(check(stones,mid,k)){ // 징검다리 건넌 친구들 수 감소시켜야함.
            start = mid;
        }
        else{ // 징검다리 건넌 친구들 수 증가시켜야함.
            end = mid;
        }
    }
    return end;
}