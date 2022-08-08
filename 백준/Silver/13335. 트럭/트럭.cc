#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n,w,l,sum;
queue<pair<int,int>> weights;
vector<pair<int,int>> cur;
vector<int> total;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w>> l;
    for(int i=0; i<n; i++){
        int weight;
        cin >> weight;
        weights.push({weight,w});
    }
    int count = 0;
    while(!weights.empty()){
        for(int i=0; i<cur.size(); i++){
            if(cur[i].second >= 0)
                cur[i].second--;
            if(cur[i].second == 0)
                total.erase(total.begin());
        }
        sum = accumulate(total.begin(),total.end(),0);
        if(l-sum >= weights.front().first){
            cur.push_back(weights.front()); 
            total.push_back(weights.front().first);
            weights.pop();
        }
        count++;
    }
    cout << count + w;
}