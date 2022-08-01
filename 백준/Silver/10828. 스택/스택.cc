#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    while(n--){
        string s;
        cin >> s;
        if(s=="push"){
            int t;
            cin >> t;
            vec.push_back(t);
        }
        else if(s=="pop"){
            if(vec.empty()) cout << -1 << "\n";
            else{
                cout << vec.back() <<"\n";
                vec.pop_back();
            }
        }
        else if(s=="size"){
            cout << vec.size() << "\n";
        }
        else if(s=="empty"){
            if(vec.empty()) cout << 1<< "\n";
            else cout << 0 << "\n";
        }
        else{
            if(vec.empty()) cout << -1 << "\n";
            else cout << vec.back() << "\n"; 
        }
    }
}