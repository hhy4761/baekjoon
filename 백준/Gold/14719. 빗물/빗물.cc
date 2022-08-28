#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int h,w;
int board[505][505];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w;
    for(int i=0; i<w; i++){
        int num;
        cin >> num;
        // q.push(num);
        for(int j=h-1; j>=h-num; j--){
            board[j][i] = 1;
        }
    }
    int left=0,right=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(board[i][j]==1){
                left = j; right=j+1;
                while(right < w and board[i][right]==0){
                    right++;
                }
                if(right < w and board[i][right]==1){
                    for(int k=left+1; k<right; k++){
                        board[i][k] =2;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<h;i++){
        for(int j=0; j<w;j++){
            if(board[i][j] == 2) ans++;
        }
    }
    cout <<ans;
}