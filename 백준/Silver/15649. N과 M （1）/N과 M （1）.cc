#include <iostream>
using namespace std;
int n,m;
int arr[10];
bool used[10];
void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++){
            cout << arr[i] <<' ';
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i]==1) continue;
        arr[cur] = i;
        used[i] = 1;
        func(cur+1);
        used[i] = 0;
    }
}
int main(){
    cin >> n >> m;
    func(0);
}