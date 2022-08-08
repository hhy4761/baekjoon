from collections import defaultdict
import re
def solution(s):
    answer = 0
    stoi = defaultdict(str)
    stoi["zero"] = '0'
    stoi["one"] = '1'
    stoi["two"] = '2'
    stoi["three"] = '3'
    stoi["four"] = '4'
    stoi["five"] = '5'
    stoi["six"] = '6'
    stoi["seven"] = '7'
    stoi["eight"] = '8'
    stoi["nine"] = '9'
    
    left,right = 0,0
    ans = ''
    while right < len(s):
        if s[right].isdigit():
            ans += s[right]
            right+=1
        else:
            while right < len(s) and not s[right].isdigit() and not stoi[s[left:right]] != '':
                right += 1
            ans += (stoi[s[left:right]])
        left = right
    
    return int(ans)