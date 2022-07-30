from math import inf
import sys
input = sys.stdin.readline

n,s = map(int,input().split())

nums = list(map(int,input().split()))

end = 0
cnt = 0
partial_sum = 0
min_len = inf
for start in range(n):

    while partial_sum < s and end < n:
        partial_sum += nums[end]
        end += 1
    if partial_sum >= s:
        min_len = min(min_len,end-start)
    
    partial_sum -= nums[start]
if min_len == inf:
    print(0)
else:
    print(min_len)