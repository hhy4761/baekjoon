#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<char> st;
    string s;
    cin >> s;
    int ans = 0;
    int temp = 1;
    bool impossible = false;
    for(int i=0; i<s.size();i++){
        char c = s.at(i);
        if(c=='('){
            temp *= 2;
            st.push('(');
        }
        else if(c=='['){
            temp*=3;
            st.push('[');
        }
        else if(c==')' and (st.empty() or st.top() !='(')) {
            impossible=true; 
            break;
        }
        else if(c==']' and (st.empty() or st.top() !='[')){
            impossible = true;
            break;
        }
        else if(c==')'){
            if(s[i-1]=='(') ans += temp;
            st.pop();
            temp/=2;
        }
        else if(c==']'){
            if(s[i-1]=='[') ans+=temp;
            st.pop();
            temp/=3;
        }

    }
    if(impossible or !st.empty()) cout << 0;
    else cout << ans;
}