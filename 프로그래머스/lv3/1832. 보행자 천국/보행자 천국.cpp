#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;
int cache[505][505][2];
int N,M;
vector<vector<int>> city_map;
int go(int i,int j, int dir,vector<vector<int>>& city_map){ // dir == 0 아래 dir ==1 오른쪽
    if(i<0 or i>=M or j<0 or j>=N) return 0;
    if(city_map[i][j]==1) return 0;
    if(i==M-1 and j==N-1) return 1;
    int& ret = cache[i][j][dir];
    if(ret != -1) return ret;
    ret = 0;

    if(city_map[i][j]==2){ // 2
        if(dir == 0) ret += go(i+1,j,dir,city_map)%MOD;
        else ret += go(i,j+1,dir,city_map)%MOD;
    }
    else{
        ret += (go(i+1,j,0,city_map)%MOD + go(i,j+1,1,city_map))%MOD;
    }
    return ret%MOD;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    N = n;
    M = m;
    city_map = city_map;
    fill(cache[0][0],cache[504][505],-1);
    return go(0,0,0,city_map);
}