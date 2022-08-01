#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> st;
    int cnt = 0;
    for(int i=0;i<s.size(); i++){
        if(s[i] == '('){
            st.push('(');
        }
        else if(s[i]==')' and s[i-1]=='('){
            st.pop();
            cnt += st.size();
        }
        else{
            st.pop();
            cnt++;
        }
    }
    cout << cnt;
}