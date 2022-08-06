#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int t,n;
string a,b;
unordered_map<string,int> m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        while(n--){
            cin >> a>> b;
            m[b]++;
        }
        int ans = 1;
        for(auto e:m){
            ans *= e.second+1;
        }
        cout << ans-1 << "\n";
        m.clear();
    }
}