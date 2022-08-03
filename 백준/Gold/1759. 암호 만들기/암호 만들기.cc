#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l,c;
int arr[15];
int comb[15];
char aeiou[5] = {'a','e','i','o','u'};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for(int i=0; i<c; i++){
        char c;
        cin >> c;
        arr[i] = int(c);
    }
    for(int i=0; i<l; i++) comb[i] = 1;
    for(int i=l; i<c; i++) comb[i] = 0;
    sort(arr,arr+c);
    sort(comb,comb+c,greater<>());
    do{
        vector<char> v;
        int vowel_cnt = 0;
        int consonant_cnt = 0;
        for(int i=0; i<c; i++){
            if(comb[i]==1){
                v.push_back(char(arr[i]));
                if(find(aeiou,aeiou+6,char(arr[i]))!=aeiou+6) vowel_cnt++;
                else consonant_cnt++;
            }
        }
        if(vowel_cnt >=1 and consonant_cnt >= 2){
            for(auto e: v) cout << e;
            cout << "\n";
        }
        v.clear();
    }while(prev_permutation(comb,comb+c));
}
