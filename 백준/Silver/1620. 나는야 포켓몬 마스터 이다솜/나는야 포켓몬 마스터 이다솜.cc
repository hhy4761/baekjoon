#include <iostream>
#include <unordered_map>
using namespace std;
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    unordered_map<string,int> h1;
    unordered_map<int,string> h2;
    int num = 1;
    while(n--){
        string s;
        cin >> s;
        h1[s] = num;
        h2[num] = s;
        num++;
    }
    while(m--){
        string question;
        cin >> question;
        if(isdigit(question[0])){
            cout << h2[stoi(question)] << "\n";
        }
        else{
            cout << h1[question] << "\n";
        }        
    }
}