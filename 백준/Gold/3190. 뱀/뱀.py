import sys
from collections import deque
input = sys.stdin.readline

n = int(input().rstrip())
grid = [[0]* n for _ in range(n)]
m = int(input().rstrip())
for _ in range(m):
    x,y = map(int,input().split())
    grid[x-1][y-1] = 2
k = int(input().rstrip())
dir = deque()
for _ in range(k):
    x,y = map(str,input().split())
    dir.append((int(x),y))

dx = [-1,0,1,0]
dy = [0,1,0,-1]

queue = deque()
queue.append((0,0))
cnt = 0
d = 1
x,y = (0,0)
while True:
    if dir:
        if dir[0][0] == cnt:
            if dir[0][1] == 'L':
                d = (d-1) % 4
            else: # D
                d = (d+1) % 4
            dir.popleft()

    x,y = x + dx[d], y + dy[d]
    cnt += 1
    if x < 0 or x >= n or y < 0 or y >= n:
        break
    if grid[x][y] == 2:
        queue.append((x,y))
        grid[x][y] = 0
    elif grid[x][y] == 0:
        if (x,y) in queue:
            break
        queue.append((x,y))
        queue.popleft()

print(cnt)
