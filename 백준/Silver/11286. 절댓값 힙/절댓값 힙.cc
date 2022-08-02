#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n;i++){
        int num;
        cin >> num;
        if(num!=0) pq.push({abs(num),num});
        else if(!pq.empty()){
            cout << pq.top().second << "\n";
            pq.pop();
        }
        else cout << 0 << "\n";
    }
}