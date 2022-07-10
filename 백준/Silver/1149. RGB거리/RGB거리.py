import sys

input = sys.stdin.readline

n = int(input().rstrip())
rgb = [[0] * 3 for _ in range(n+1) ] 
dp = [[0]* 3 for _ in range(n+1)]
for i in range(1,n+1):
    rgb[i] = list(map(int,input().split()))

dp[1][0] = rgb[1][0]
dp[1][1] = rgb[1][1]
dp[1][2] = rgb[1][2]

for i in range(2,n+1):
    for j in range(3):
        if j == 0:
            dp[i][j] = min(dp[i-1][1],dp[i-1][2]) + rgb[i][0]
        elif j == 1:
            dp[i][j] = min(dp[i-1][0],dp[i-1][2]) + rgb[i][1]
        elif j == 2:
            dp[i][j] = min(dp[i-1][0],dp[i-1][1]) + rgb[i][2]

print(min(dp[n]))