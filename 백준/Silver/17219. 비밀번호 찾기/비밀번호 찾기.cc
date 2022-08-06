#include <iostream>
#include <unordered_map>
using namespace std;

int n,k;
unordered_map<string,string> m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    while(n--){
        string first,second;
        cin >> first >> second;
        m.insert({first,second});
    }
    while(k--){
        string s;
        cin >> s;
        cout << m[s] << '\n';
    }
}