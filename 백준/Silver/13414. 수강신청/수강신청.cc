#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int k,l;
unordered_map<string,int> m;

bool cmp(pair<string,int> &a, pair<string,int> &b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> l;
    for(int i=0; i<l; i++){
        string num;
        cin >> num;
        if(m.find(num)!=m.end()){
            m.erase(num);
            m.insert({num,i});
        }
        else m.insert({num,i});
    }
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); i++){
        if(i==k) break;
        cout << v[i].first << "\n";
    }
}