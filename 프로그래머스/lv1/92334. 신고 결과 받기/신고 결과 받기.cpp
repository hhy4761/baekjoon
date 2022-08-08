#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
vector<string> split(string input, char delimeter){
    vector<string> res;
    stringstream ss(input);
    string temp;
    
    while(getline(ss,temp,delimeter)){
        res.push_back(temp);
    }
    return res;
}
unordered_map<string,unordered_set<string>> reported_list;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string,int> m;
    for(auto id: id_list) m[id] = 0;
    for(auto e:report){
        vector<string> r = split(e,' ');
        string reporter = r[0]; string reported = r[1];
        reported_list[r[1]].insert(r[0]);
    }
    for(auto e: reported_list){
        if(e.second.size() >= k){
            for(auto name : e.second){
                m[name]++;
            }
        }
    }
    for(auto id: id_list){
        answer.push_back(m[id]);
    }
    return answer;
}