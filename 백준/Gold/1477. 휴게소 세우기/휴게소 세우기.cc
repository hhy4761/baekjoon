#include <iostream>
#include <algorithm>
using namespace std;

int n,m,l;
int place[52];
int ans = 1000;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    place[0] = 0; place[n+1] = l;
    for(int i=1; i<=n; i++)
        cin >> place[i];
    sort(place,place+n+2);
    int left = 1, right = l-1;
    while(left <= right){
        int rest = 0;
        int mid = (left+right) / 2;

        for(int i=1; i<=n+1; i++){
            int dist = place[i] - place[i-1];
            int cnt = dist / mid;

            if(cnt > 0 ){
                if(dist % mid == 0) rest += cnt-1; 
                else rest += cnt;
            }
        }
        if(rest > m) left = mid + 1;
        else{
            right = mid - 1;
            ans = min(mid,ans);
        }
    }
    cout << ans <<"\n";
    return 0;
}