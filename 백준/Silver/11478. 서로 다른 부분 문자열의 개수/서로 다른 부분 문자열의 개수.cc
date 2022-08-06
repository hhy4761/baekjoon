#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
string s,substring;
unordered_set<string> subs;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i=0; i<s.size();i++){
        for(int j=1; j<=s.size(); j++){
            substring = s.substr(i,j);
            subs.insert(substring);
        }
    }
    cout << subs.size();
}