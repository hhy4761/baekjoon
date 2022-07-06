import sys
from itertools import combinations

input = sys.stdin.readline
n,m = map(int,input().split())
ans = (list(combinations(range(1,n+1),m)))
for a in ans:
    for i in range(len(a)):
        print(a[i],end=" ")
    print()
