#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool blue[4][6];
bool green[6][4];
int n,ans,total;

int move_to_blue(int t, int x){
    if(t==1){
        for(int i=0; i<=4; i++){
            if(!blue[x][i]){
                if(!blue[x][i+1]){
                    if(i==4){ // 끝까지 도달한 경우
                        blue[x][5] = true;
                        return 5;
                    }
                }
                else{ // 현재 위치는 비어있으나 다음 위치는 차있음.
                    blue[x][i] = true;
                    return i;
                }
            }
        }
    }
    else if(t==2){
        for(int i=0; i<=3; i++){
            if(!blue[x][i] and !blue[x][i+1]){
                if(!blue[x][i+2]){
                    if(i==3){
                        blue[x][4] = true;
                        blue[x][5] = true;
                        return 4;
                    }
                }
                else{
                    blue[x][i] = true;
                    blue[x][i+1] = true;
                    return i;
                }
            }
        }
    }
    else if(t==3){
        for(int i=0; i<=4; i++){
            if(!blue[x][i] and !blue[x+1][i]){
                if(!blue[x][i+1] and !blue[x+1][i+1]){
                    if(i==4){
                        blue[x][5] = true;
                        blue[x+1][5] = true;
                        return 5;
                    }
                }
                else{
                    blue[x][i] = true;
                    blue[x+1][i] = true;
                    return i;
                }
            }
        }
    }
}

int move_to_green(int t, int y){
    if(t==1){
        for(int i=0; i<=4; i++){
            if(!green[i][y]){
                if(!green[i+1][y]){
                    if(i==4){
                        green[5][y] = true;
                        return 5;
                    }
                }
                else{
                    green[i][y] = true;
                    return i;
                }
            }
        }
    }
    else if(t==2){
        for(int i=0; i<=4; i++){
            if(!green[i][y] and !green[i][y+1]){
                if(!green[i+1][y] and !green[i+1][y+1]){
                    if(i==4){
                        green[5][y] = true;
                        green[5][y+1] = true;
                        return 5;
                    }
                }
                else{
                    green[i][y] = true;
                    green[i][y+1] = true;
                    return i;
                }
            }
        }
    }
    else if(t==3){
        for(int i=0; i<=3; i++){
            if(!green[i][y] and !green[i+1][y]){
                if(!green[i+2][y]){
                    if(i==3){
                        green[4][y] = true;
                        green[5][y] = true;
                        return 4;
                    }
                }
                else{
                    green[i][y] = true;
                    green[i+1][y] = true;
                    return i;
                }
            }
        }
    }
}

int check_row(){
    for(int i=5; i>=2; i--){
        bool find = true;
        for(int j=0; j<4; j++){
            if(!green[i][j]){
                find = false;
                break;
            }
        }
        if(find) return i;
    }
    return -1;
}

void drop_down(int row){
    ans++;
    for(int i=0; i<4; i++) green[row][i] = false;
    for(int i=row-1; i>=0; i--){
        for(int j=0; j<4; j++){
            green[i+1][j] = green[i][j];
        }
        for(int j=0; j<4; j++){
            green[i][j] = false;
        }
    }
}

int check_col(){
    for(int j=5; j>=2; j--){
        bool find = true;
        for(int i=0; i<4; i++){
            if(!blue[i][j]){
                find = false;
                break;
            }
        }
        if(find) return j;
    }
    return -1;
}

void push_right(int col){
    ans++;
    for(int i=0; i<4; i++) blue[i][col] = false;
    for(int j=col-1; j>=0; j--){
        for(int i=0; i<4; i++){
            blue[i][j+1] = blue[i][j];
        }
        for(int i=0; i<4; i++){
            blue[i][j] = false;
        }
    }
}

int check_overflow_green(){
    int max_count = -1;
    for(int j=0; j<4; j++){
        int cnt = 0;
        for(int i=0; i<2; i++){
            if(green[i][j]) cnt++;
        }
        max_count = max(max_count,cnt);
    }
    return max_count;
}

int check_overflow_blue(){
    int max_count = -1;
    for(int i=0; i<4; i++){
        int cnt = 0;
        for(int j=0; j<2; j++){
            if(blue[i][j]) cnt++;
        }
        max_count = max(max_count,cnt);
    }
    return max_count;
}

void countG(){
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            if(green[i][j]) total++;
        }
    }
}

void countB(){
    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
            if(blue[i][j]) total++;
        }
    }
}

void printG(){
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            cout << green[i][j] << " ";
        }
        cout << "\n";
    }
}

void printB(){
    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
            cout << blue[i][j] << " ";
        }
        cout <<"\n";
    }
}

int main(){
    fastio
    cin >> n;
    while(n--){
        int t,x,y;
        cin >> t >> x >> y;
        move_to_blue(t,x);
        move_to_green(t,y);
        
        while(true){
            int row = check_row();
            if(row==-1) break;
            drop_down(row);
        }
        while(true){
            int col = check_col();
            if(col==-1) break;
            push_right(col);
        }
        int overB = check_overflow_blue();
        for(int i=0; i<overB; i++){
            push_right(5);
            ans--;
        }

        int overG = check_overflow_green();
        for(int i=0; i<overG; i++) {
            drop_down(5);
            ans--;
        }
    }
    countG(); countB();
    cout << ans << "\n" << total;
}