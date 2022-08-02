#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    unordered_map<string,bool> m;
    while(n--){
        string name;
        string enter_or_leave;
        cin >> name >> enter_or_leave;
        if(enter_or_leave == "enter") {
            m[name] = 1;
        }
        else {
            m.erase(name);
        }
    }
    vector<pair<string,bool>> ans(m.begin(),m.end());
    sort(ans.begin(),ans.end(), greater<>());
    for(auto e:ans){
        cout << e.first << "\n";
    }
}