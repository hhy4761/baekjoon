import sys
from collections import deque
from itertools import combinations

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def outside_air():
    queue = deque([(0,0)])
    visited = set()
    while queue:
        x,y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= n or nx < 0 or ny >= m or ny < 0:
                continue
            if (nx,ny) not in visited and (grid[nx][ny] == -1 or grid[nx][ny] == 0):
                queue.append((nx,ny))
                visited.add((nx,ny))
                grid[nx][ny] = -1

def melt():
    queue = deque([(0,0)])
    visited = set()
    while queue:
        x,y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= n or nx < 0 or ny >= m or ny < 0:
                continue
            elif (nx,ny) not in visited and (grid[nx][ny] == -1 or grid[nx][ny] == 0):
                queue.append((nx,ny))
                visited.add((nx,ny))
            elif grid[nx][ny] >= 1:
                grid[nx][ny] += 1

    for i in range(n):
        for j in range(m):
            if grid[i][j] >= 3:
                grid[i][j] = 0
            elif grid[i][j] == 2:
                grid[i][j] = 1

def is_all_melt():
    ret = True
    for i in range(n):
        for j in range(m):
            if grid[i][j] >= 1:
                ret = False
                return ret
    return ret

input = sys.stdin.readline
n,m = map(int,(input().split()))
grid = [[0]*m for _ in range(n)]
for i in range(n):
    grid[i] = list(map(int,input().split()))
count = 0
while not is_all_melt():
    outside_air()
    melt()
    count += 1
print(count)