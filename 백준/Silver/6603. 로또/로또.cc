#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> nums;
vector<int> comb;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        cin >> n;
        if(n==0) break;
        for(int i=0; i<n;i++){
            int num;
            cin >> num;
            nums.push_back(num);
        }
        for(int i=0; i<6; i++) 
            comb.push_back(1);
        for(int i=6; i<n; i++) 
            comb.push_back(0); 
        sort(nums.begin(),nums.end());
        sort(comb.begin(),comb.end(),greater<>());
        do{
            for(int i=0; i<n;i++) {
                if(comb[i]==1)
                    cout << nums[i] << ' ';
            }
            cout << "\n";
        }while(prev_permutation(comb.begin(),comb.end()));
        nums.clear();
        comb.clear();
        cout << "\n";
    }
}