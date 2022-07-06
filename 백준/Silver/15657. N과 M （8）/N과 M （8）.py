import sys
from itertools import combinations_with_replacement 

input = sys.stdin.readline
n,m = map(int,input().split())
nums = list(map(int,input().split()))
nums.sort()
ans = (list(combinations_with_replacement (nums,m)))
for a in ans:
    for i in range(len(a)):
        print(a[i],end=" ")
    print()
