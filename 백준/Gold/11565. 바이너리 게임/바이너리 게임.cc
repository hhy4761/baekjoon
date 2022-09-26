#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
string a,b;
unordered_set<string> us;
bool ans;
int check(string& s){
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1') cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    
    int aNum = check(a);
    int bNum = check(b);
    if((aNum < bNum and aNum %2 == 0) or (aNum + 1 < bNum and aNum%2 != 0)) cout << "DEFEAT";
    else cout << "VICTORY";
}