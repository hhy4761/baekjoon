#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int tc,f;
unordered_map<string,string> parent;
unordered_map<string,int> cnt;
string find(string a){
    if(parent[a] == a) return a;
    parent[a] = find(parent[a]);
    return parent[a];
}
bool merge(string a,string b){
    a = find(a);
    b = find(b);
    if(a==b){
        cout << cnt[a] << "\n";
        return false;
    }
    if(a < b) {
        parent[b] = a;
        cnt[a] += cnt[b];
        cout << cnt[a] << "\n";
    }
    else {
        parent[a] = b;
        cnt[b] += cnt[a];
        cout << cnt[b] << "\n";
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> f;
        vector<pair<string,string>> input;
        while(f--){
            string a,b;
            cin >> a >> b;
            parent[a] = a;
            cnt[a] = 1;
            parent[b] = b;
            cnt[b] = 1;
            input.push_back({a,b});
        }
        for(int i=0; i<input.size(); i++){
            merge(input[i].first,input[i].second);
        }
    }
}