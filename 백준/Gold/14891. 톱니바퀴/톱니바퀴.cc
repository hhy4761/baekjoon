#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

vector<deque<int>> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,num,dir;
    deque<int> empty;
    v.push_back(empty); // for 1-index, Insert dummy value 
    for(int i=0; i<4; i++){
        string s;
        deque<int> d;
        cin >> s;
        for(auto chr : s){
            d.push_back(chr-'0');
        }
        v.push_back(d);
    }
    cin >> k;
    while(k--){
        cin >> num >> dir;
        deque<pair<int,int>> dq;
        bool vis[5] = {};
        dq.push_back({num,dir});
        vis[num] = 1;
        while(!dq.empty()){
            int cur;
            tie(cur,dir) = dq.front(); dq.pop_front();
            if(cur==1){
                if(v[cur][2] != v[cur+1][6] and !vis[cur+1]){
                    dq.push_back({cur+1,dir*-1});
                    vis[cur+1] = 1;
                } 
            }
            else if(cur==v.size()-1){
                if(v[cur][6] != v[cur-1][2] and !vis[cur-1]){
                    dq.push_back({cur-1,dir*-1});
                    vis[cur-1] = 1;
                } 
            }
            else{
                if(v[cur][2] != v[cur+1][6] and !vis[cur+1]){
                    dq.push_back({cur+1,dir*-1});
                    vis[cur+1] = 1;
                } 
                if(v[cur][6] != v[cur-1][2] and !vis[cur-1]){
                    dq.push_back({cur-1,dir*-1});
                    vis[cur-1] = 1;
                } 
            }
            if(dir == -1){
                int top = v[cur].front(); v[cur].pop_front();
                v[cur].push_back(top);
            }
            else{
                int tail = v[cur].back(); v[cur].pop_back();
                v[cur].push_front(tail);
            }
        }
    }
    cout << v[1][0] + v[2][0]*2 + v[3][0]*4 + v[4][0]*8;
}