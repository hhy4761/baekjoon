from re import L
import sys

input = sys.stdin.readline

n,k = map(int,input().split())
bag = [[0,0]] * (n+1)
dp = [[0]* (k+1) for _ in range(n+1)]
for i in range(1,n+1):
    w,v = map(int,input().split())
    bag[i] = [w,v]

for item in range(1,n+1):
    for weight in range(1,k+1):
        if weight >= bag[item][0]:
            dp[item][weight] = max(dp[item-1][weight], dp[item-1][weight-bag[item][0]] + bag[item][1])
        else:
            dp[item][weight] = dp[item-1][weight]

print(dp[n][k])