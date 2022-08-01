#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<char> v;
    
    while(1){
        getline(cin,s);
        if (s==".") break;
        bool is_success = true;
        for(auto c : s){
            if(c=='.') break;
            if(c=='(' || c=='{' || c=='[') v.push_back(c);
            else if(c==')'){
                if(v.back()=='(') v.pop_back();
                else{
                    is_success = false;
                    break;
                }
            }
            else if(c=='}'){
                if(v.back()=='{') v.pop_back();
                else{
                    is_success = false;
                    break;
                }
            }
            else if(c==']'){
                if(v.back()=='[') v.pop_back();
                else{
                    is_success = false;
                    break;
                }
            }
        }
        if(is_success && v.empty()) cout << "yes" << "\n";
        else cout << "no\n";
        v.clear();
    }
}