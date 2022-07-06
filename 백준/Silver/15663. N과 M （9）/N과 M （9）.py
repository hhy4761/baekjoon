import sys
from itertools import permutations 

input = sys.stdin.readline
n,m = map(int,input().split())
nums = list(map(int,input().split()))
ans = (set(permutations(nums,m)))
ans = list(ans)
ans.sort()
for a in ans:
    for i in range(len(a)):
        print(a[i],end=" ")
    print()
