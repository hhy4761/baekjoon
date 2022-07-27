import sys
from bisect import bisect_left

input = sys.stdin.readline
N,H = map(int,input().split())
upper = []
lower = []
for i in range(N):
    if i%2 ==0:
        lower.append(int(input().rstrip()))
    else:
        upper.append(int(input().rstrip()))

upper.sort()
lower.sort()
cnt = 1

min_val = float('inf')
for h in range(1,H+1):
    u,l = bisect_left(upper,H-(h-0.5)),bisect_left(lower,h-0.5)
    total = N - (u+l)
    if total < min_val:
        min_val = total
        cnt = 1
    elif total == min_val:
        cnt += 1

print(min_val,cnt)