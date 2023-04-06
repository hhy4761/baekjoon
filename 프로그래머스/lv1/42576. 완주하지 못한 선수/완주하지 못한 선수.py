from collections import defaultdict
def solution(participant, completion):
    ans = defaultdict(int)
    for p in participant:
        ans[p]+=1
    for c in completion:
        ans[c]-=1
    for a in ans:
        if ans[a] == 1:
            return a