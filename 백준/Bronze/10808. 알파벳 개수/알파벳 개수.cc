#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >>str;
    for(char c='a'; c<='z';c++){
        int cnt =0;
        for(char e:str)
        {
            if(e==c)
                cnt++;
        }
        cout << cnt <<" ";
    }
}