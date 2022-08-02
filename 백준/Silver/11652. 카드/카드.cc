#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<long long> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        long long num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int left,right;
    left = 0; right=0;
    int max_cnt = 0;
    long long max_val = INT64_MAX;
    while(right < v.size()){
        int cnt = 0;
        while(right < v.size() and v[left]==v[right]){
            right++;
            cnt++;
        }
        if(max_cnt < cnt) {
            max_cnt = cnt;
            max_val = v[left];
        }
        left = right;
    }
    cout << max_val;
}