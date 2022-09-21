#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
unordered_set<string> listGem;
unordered_map<string,int> curGems;
vector<int> ans(2);

vector<int> solution(vector<string> gems) {
    
    for(auto &e : gems) listGem.insert(e);
    int totalGem = listGem.size(); // 보석의 총 개수
    int curGem = 0; // 현재 보석의 개수
    
    int left = 0, right = 0, minLen = INT32_MAX;
    bool fix = false;
    while(left <= right and right < gems.size()){ // 현재 탐색 범위의 보석 개수가 총 개수가 될 때까지 right 증가
        
        if(curGems[gems[right]] == 0) curGem++;
        if(!fix) curGems[gems[right]]++;
        
        if(curGem == totalGem){
            if(minLen > right-left){
                ans[0] = left+1;
                ans[1] = right+1;
                minLen = right-left;
            }
            curGems[gems[left]]--;
            if(curGems[gems[left]] == 0) curGem--;
            left++;
            fix = true;
        }
        else {
            right++;
            fix = false;
        }
        
    }
    
    return ans;
}