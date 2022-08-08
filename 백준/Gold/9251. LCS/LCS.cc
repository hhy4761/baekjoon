#include <iostream>
#include <string>
using namespace std;
string a,b;
int d[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    string c= " ";
    a = c.append(a);
    for(int i=1; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    // for(int i=0; i<a.size(); i++){
    //     for(int j=0; j<b.size();j++){
    //         cout << d[i][j] << ' ';
    //     }
    //     cout <<"\n";
    // }
    cout << d[a.size()-1][b.size()-1];
}