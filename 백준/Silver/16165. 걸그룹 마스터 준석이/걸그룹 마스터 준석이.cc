#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
string team,name;
unordered_map<string,vector<string>> team_to_name;
unordered_map<string,string> name_to_team;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(n--){
        cin >> team;
        cin >> k;
        while(k--){
            cin >> name;
            team_to_name[team].push_back(name);
            name_to_team[name] = team;
        }
    }
    while(m--){
        cin >> name >> k;
        if(k==1){
            cout << name_to_team[name] << '\n';
        }
        else{
            sort(team_to_name[name].begin(),team_to_name[name].end());
            for(auto e:team_to_name[name]) cout << e << "\n";
        }
    }
}