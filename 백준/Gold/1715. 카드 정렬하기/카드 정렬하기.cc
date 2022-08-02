#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<int,vector<int>,greater<>> pq;
int main(){
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        pq.push(num);
    }
    int total = 0;
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        total += a+b;
    }
    cout << total;
}