#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int R,C,M;
int total;
queue<tuple<int,int,int>> shark[105][105];


void getShark(int cur){
    for(int i=1; i<=R; i++){
        if(!shark[i][cur].empty()){
            int s,d,z;
            tie(s,d,z) = shark[i][cur].front();
            total += z;
            shark[i][cur].pop();
            break;
        }
    }
}

void moveShark(){
    queue<tuple<int,int,int>> tmpShark[105][105];
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(!shark[i][j].empty()){
                int r,c,s,d,z;
                r = i, c = j;
                tie(s,d,z) = shark[i][j].front(); shark[i][j].pop();
                int tmp;
                if(d==1 or d==2)
                    tmp = s % (2*R-2);
                else
                    tmp = s % (2*C-2);
                while(tmp--){
                    if(d==1){
                        r--;
                        if(r==0){
                            r += 2;
                            d=2;
                        }
                    }
                    else if(d==2){ //아래
                        r++;
                        if(r==R+1){
                            r -= 2;
                            d=1;
                        }
                    }
                    else if(d==3){ //오른쪽
                        c++;
                        if(c==C+1){
                            c -= 2;
                            d = 4;
                        }
                    }
                    else if(d==4){ //왼쪽
                        c--;
                        if(c==0){
                            c += 2;
                            d = 3;
                        }
                    }
                }
                tmpShark[r][c].push(make_tuple(s,d,z));
            }
        }
    }
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            shark[i][j] = tmpShark[i][j];
}

void eatShark(){ // 2마리 이상 있는 경우 제거
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(shark[i][j].size() >= 2){
                tuple<int,int,int> lastShark;
                int maxZ = -1;
                while(!shark[i][j].empty()){
                    int s,d,z;
                    tie(s,d,z) = shark[i][j].front(); shark[i][j].pop();
                    if(maxZ < z){
                        maxZ = z;
                        lastShark = make_tuple(s,d,z);
                    }
                }
                shark[i][j].push(lastShark);
            }
        }
    }
}

void printShark(){
    cout << "\n";
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            int tmp = shark[i][j].size();
            while(tmp--){
                int s,d,z;
                tie(s,d,z) = shark[i][j].front(); shark[i][j].pop();
                cout << i << " " << j << " " << s << " " << d << " " << z << "\n";
                shark[i][j].push(make_tuple(s,d,z));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> M;
    for(int i=0; i<M; i++){
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        shark[r][c].push(make_tuple(s,d,z));
    }
    for(int i=1; i<=C; i++){
        getShark(i);
        moveShark();
        eatShark();
    }
    
    cout << total <<"\n";
}