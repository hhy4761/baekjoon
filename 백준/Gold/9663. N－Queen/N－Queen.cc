#include <iostream>
using namespace std;
int n;
int cnt = 0;
bool used1[30]; // 열 
bool used2[30]; // x+y 우상향 대각선
bool used3[30]; // x-y+(n-1) 우하향 대각선
int ans[15];
void dfs(int cur){
    if(cur==n){
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){ // cur == 행(x) , i == 열(y)
        if(!used1[i] and !used2[cur+i] and !used3[cur-i+(n-1)]){
            used1[i] = 1;
            used2[cur+i] = 1;
            used3[cur-i+(n-1)] = 1;
            dfs(cur+1);
            used1[i] = 0;
            used2[cur+i] = 0;
            used3[cur-i+(n-1)] = 0;
            
        }
    }
}
int main(){
    cin >> n;
    dfs(0);
    cout << cnt;
}