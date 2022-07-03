import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline
n,m = map(int,(input().split()))
grid = [[0]*n for _ in range(n)]
for i in range(n):
    grid[i] = list(map(int,input().split()))

chicken_arr = []
# Find chicken in grid 
for i in range(n):
    for j in range(n):
        if grid[i][j] == 2:
            chicken_arr.append((i,j))

chicken_arr = list(combinations(chicken_arr,m))

ans = []
for i in range(len(chicken_arr)):
    dist_arr = []
    for x in range(n):
        for y in range(n):
            if grid[x][y] == 1:
                dist = 9999
                for k in range(len(chicken_arr[i])):
                    dist = min(dist,abs(x-chicken_arr[i][k][0])+abs(y-chicken_arr[i][k][1]))
                dist_arr.append(dist)
    ans.append(sum(dist_arr))
print(min(ans))