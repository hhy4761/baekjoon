from cmath import inf
import sys

input = sys.stdin.readline
n = int(input().rstrip())
li = list(map(int,input().split()))
left,right = 0,n-1
ans = [inf,inf]

while left < right:
    find = False
    val = (li[left]+li[right])
    if val == 0:
        print(li[left],li[right])
        find = True
        break
    elif abs(val) < abs(ans[0]+ans[1]):
        ans[0] = li[left]
        ans[1] = li[right]
    if val > 0:
        right -= 1
    elif val < 0:
        left += 1
if not find:
    print(ans[0],ans[1])
