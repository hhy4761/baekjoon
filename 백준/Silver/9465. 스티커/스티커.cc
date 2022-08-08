#include <iostream>
#include <algorithm>
using namespace std;

int score[3][100001];
int d[3][100001];
int t,n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=2; i++)
            for(int j=1; j<=n; j++)
                cin >> score[i][j];
        d[1][1] = score[1][1]; d[2][1] = score[2][1];
        d[1][2] = d[2][1] + score[1][2]; d[2][2] = d[1][1] + score[2][2];
        for(int j=3; j<=n; j++){
            for(int i=1; i<=2; i++){
                if(i==1){
                    d[i][j] = max(d[2][j-1],d[2][j-2]) + score[i][j];
                }
                else if(i==2){
                    d[i][j] = max(d[1][j-1],d[1][j-2]) + score[i][j];
                }
            }
        }
        cout << max(d[1][n],d[2][n]) << '\n';
    }
}