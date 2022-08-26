#include <iostream>
using namespace std;

// int n,m,d;
// int board[20][20];
// int main(){
//     cin >> n >> m >> d;
//     for(int i=0;i<n;i++){
//         for(int j=0; j<m; j++){
//             cin >> board[i][j];
//         }
//     }

// }

int n,a,b,c;
int board[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> board[i];
    cin >> b >> c;
    long long ans = 0;
    for(int i=0; i<n; i++){
        board[i] -= b;
        ans ++;
        if(board[i] > 0){
            if(board[i]%c == 0){
                ans += board[i]/c;
            }
            else{
                ans += board[i]/c + 1;
            }
        }
    }
    cout << ans;
}