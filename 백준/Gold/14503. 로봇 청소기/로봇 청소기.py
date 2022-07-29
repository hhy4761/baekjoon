import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())
r,c,d = map(int,input().split())

grid = [[] for _ in range(n)]
for i in range(n):
    grid[i] = list(map(int,input().split()))

dx = [-1,0,1,0]
dy = [0,1,0,-1]

def clear(x,y):
    if grid[x][y] == 0:
        grid[x][y] = -1
        return True
    return False

def change_dir(x,y,d):
    for i in range(1,5):
        nx = x + dx[(d-i) % 4]
        ny = y + dy[(d-i) % 4]

        if grid[nx][ny] == 0:
            return (nx,ny,(d-i) % 4)

    return (x,y,d)

def move_back(x,y,d):
    x = x+dx[(d-2) % 4]
    y = y+dy[(d-2) % 4]
    return (x,y)

queue = deque()
queue.append((r,c,d))
cnt = 0
while queue:
    cur_x,cur_y,cur_d = queue.popleft()
    if clear(cur_x,cur_y):
        cnt += 1
    next_x,next_y,next_d = change_dir(cur_x,cur_y,cur_d)
    if cur_x == next_x and cur_y == next_y:
        back_x,back_y = move_back(cur_x,cur_y,cur_d)
        if grid[back_x][back_y] == 1:
            break
        else:
            queue.append((back_x,back_y,cur_d))
    else:
        queue.append((next_x,next_y,next_d))

print(cnt)