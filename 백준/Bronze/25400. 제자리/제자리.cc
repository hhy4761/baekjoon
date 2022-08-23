#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int card[250001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=1; i<=n; i++)
        cin >> card[i];
    int cur = 1;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(card[i] == cur){
            cur++;
            continue;
        }
        else{
            cnt++;
        }
    }
    cout << cnt;
}