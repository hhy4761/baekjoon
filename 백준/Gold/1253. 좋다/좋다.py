import sys
from collections import defaultdict
input = sys.stdin.readline
n = int(input().rstrip())
arr = list(map(int,input().split()))
arr.sort()

res = 0
for i in range(n):
    temp = arr[:i] + arr[i+1:]
    start,end = 0,n-2

    while start < end :
        total = temp[start] + temp[end]
        if total == arr[i]:
            res += 1
            break
        elif total < arr[i]:
            start += 1
        else:
            end -= 1
print(res)