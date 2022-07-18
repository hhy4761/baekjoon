import sys,time,re
from collections import defaultdict,deque

input = sys.stdin.readline
grid = [list(input().rstrip()) for _ in range(12)]
visited = [[False]*6 for _ in range(12)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

# 폭발 후 정리
def reflect():
    global grid
    
    for i in range(6):
        s = []
        for j in range(11,-1,-1):
            if grid[j][i] != '.':
                s.append(grid[j][i])
        for _ in range(12-len(s)):
            s.append(".")
        s.reverse()
        for j in range(11,-1,-1):
            grid[j][i] = s[j]
# 폭발
def boom(i,j):
    global grid
    global visited
    q = deque()
    visit = set()
    q.append((i,j,grid[i][j]))
    visit.add((i,j))
    visited[i][j] = True
    while q:
        x,y,color = q.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or nx >= 12 or ny < 0 or ny >=6:
                continue
            if (nx,ny) not in visit and grid[nx][ny] == color:
                q.append((nx,ny,color))
                visit.add((nx,ny))
                visited[x][y] = True
    # 폭발
    if len(visit) >= 4:
        for x,y in visit:
            grid[x][y] = '.'
        return True
    else:
        return False

cnt = 0
while True: 
    visited = [[False]*6 for _ in range(12)]
    is_boom = False
    for i in range(12):
        for j in range(6):
            if not visited[i][j] and grid[i][j] == '.':
                visited[i][j] = True

            elif not visited[i][j] and grid[i][j] != '.':
                if boom(i,j):
                    is_boom = True
                # print(*visited,sep='\n')
                
    if is_boom:
        cnt += 1
        reflect()

    else:
        break
print(cnt)