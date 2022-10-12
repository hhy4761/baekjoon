#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,k;
vector<int> a;
vector<bool> used;
vector<int> robots;
void rotate_belt(){
    int complete = -1;
    rotate(a.begin(),a.begin()+(2*n-1),a.end());
    rotate(used.begin(),used.begin()+(2*n-1),used.end());
    for(int i=0; i<robots.size(); i++){
        used[robots[i]] = false;
        used[robots[i]+1] = true;
        robots[i]++;
        if(robots[i] == n-1) complete = i;
    }
    if(complete != -1){
        used[robots[complete]] = false;
        robots.erase(robots.begin()+complete);
    } 
}

void move_robot(){
    int complete = -1;
    for(int i=0; i<robots.size(); i++){
        if(a[robots[i]+1] >=1 and !used[robots[i]+1]){
            used[robots[i]] = false;
            used[robots[i]+1] = true;
            a[robots[i]+1]--;
            robots[i]++;
            if(robots[i] == n-1) complete = i;
        } 
    }
    if(complete != -1){
        used[robots[complete]] = false;
        robots.erase(robots.begin()+complete);
    }
}

void load_robot(){
    if(a[0] > 0 and !used[0]){
        robots.push_back(0);
        used[0] = true;
        a[0]--;
    }
}

bool check_k(){
    int cnt = 0;
    for(int i=0; i<2*n; i++){
        if(a[i] <= 0) cnt++;
    }
    if(cnt >= k) return false;
    return true;
}

int main(){
    fastio
    cin >> n >> k;
    for(int i=0; i<2*n; i++){
        int val;
        cin >> val;
        a.push_back(val);
        used.push_back(false);
    }
    int cur = 0;
    while(check_k()){
        cur++;
        rotate_belt();
        move_robot();
        load_robot();
    }
    cout << cur;
}