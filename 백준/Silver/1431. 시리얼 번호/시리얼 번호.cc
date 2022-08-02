#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> v;
bool comp(string &a,string &b){
    if(a.size() != b.size()) return a.size() < b.size() ;
    else{
        int num_a = 0; 
        int num_b = 0;
        for(auto &a_ele : a){
            if(isdigit(a_ele)) num_a+=a_ele-'0';
        }
        for(auto &b_ele : b){
            if(isdigit(b_ele)) num_b+=b_ele-'0';
        }
        if(num_a != num_b){
            return num_a < num_b;
        }
        else{
            return a < b;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),comp);
    for(auto e: v) cout << e << "\n";
}