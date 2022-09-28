#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

string input;
int T[30];
vector<int> adj[30],rev[30];
queue<int> q;
int deg[30];
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin,input)){
        char cur; string prev; int t; 
        stringstream s(input);
        s >> cur >> t;
        T[cur-'A'] = t;
        if(s >> prev){
            for(char& c : prev){
                adj[c-'A'].push_back(cur-'A');
                rev[cur-'A'].push_back(c-'A');
                deg[cur-'A']++;
            }
        }
    }
    for(int i=0; i<26; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(auto& nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0){
                int maxT = -1;
                for(auto& e : rev[nxt]) maxT = max(maxT, T[e]);
                T[nxt] += maxT; 
                q.push(nxt);
            }
        }
        ans = max(ans, T[cur]);
    }
    cout << ans;
}