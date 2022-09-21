#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int total[360000];
vector<string> split(string input, char deli);

int stringToTime(string time){
    vector<string> t = split(time,':');
    return stoi(t[0]) * 3600 + stoi(t[1])*60 + stoi(t[2]);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playSec = stringToTime(play_time);
    int advSec = stringToTime(adv_time);
    
    for(auto& e: logs){
        vector<string> log = split(e,'-');
        int startTime = stringToTime(log[0]);
        int endTime = stringToTime(log[1]);
        for(int i=startTime; i<endTime; i++) {
            total[i]++;
        }
    }
        
    long long curSum = 0;
    for(int i=0; i<advSec; i++) curSum += total[i];

    long long maxSum = curSum;
    int maxIdx = 0;
    for(int i=advSec; i<playSec; i++){
        curSum += total[i];
        curSum -= total[i-advSec];
        if(curSum > maxSum){
            maxIdx = i-advSec+1;
            maxSum = curSum;
        }
    }
    int h,m,s;
    h = maxIdx/3600;
    m = maxIdx/60%60;
    s = maxIdx%60;
    char buf[10];
    sprintf(buf,"%02d:%02d:%02d",h,m,s);
    answer = buf;
    return answer;
}

vector<string> split(string input, char deli){
    vector<string> v;
    stringstream ss(input);
    string tmp;
    while(getline(ss,tmp,deli)){
        v.push_back(tmp);
    }
    return v;
}