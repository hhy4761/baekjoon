#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> ans;
int main(){
    cin >> n ;
    while(n--){
        int arrive, waiting;
        cin >> arrive >> waiting;
        if(arrive > waiting) continue;
        else ans.push_back(waiting);
    }
    if(ans.empty()) cout << -1;
    else cout << *min_element(ans.begin(),ans.end());
}