#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int nums[10];
bool idx[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        nums[i] = i;
    }
    for(int i=1;i<=m;i++){
        idx[i] = 1;
    }
    for(int i=m+1; i<=n;i++){
        idx[i] = 0;
    }
    do{
        for(int i=1;i<=n;i++){
            if(idx[i]==1)
                cout << nums[i] << ' ';
        }
        cout << "\n";
    }while(prev_permutation(idx+1,idx+n+1));
}