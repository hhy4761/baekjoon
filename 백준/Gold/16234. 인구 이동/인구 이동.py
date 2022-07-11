import sys
import time
input = sys.stdin.readline

n,l,r = map(int,input().split())
grid = [list(map(int,input().split())) for _  in range(n)]

# grid[i][j] = 인구, 상,하,좌,우
for i in range(n):
    for j in range(n):
        grid[i][j] = [grid[i][j],False,False,False,False]

# 국경선 오픈
for i in range(n):
    for j in range(n):
        if i < n-1 and (l <= abs(grid[i][j][0] - grid[i+1][j][0]) <= r):
            grid[i][j][2] = True
        if j < n-1 and (l <= abs(grid[i][j][0] - grid[i][j+1][0]) <= r):
            grid[i][j][4] = True
        if i > 0 and (l <= abs(grid[i][j][0] - grid[i-1][j][0]) <= r):
            grid[i][j][1] = True
        if j > 0 and (l <= abs(grid[i][j][0] - grid[i][j-1][0]) <= r):
            grid[i][j][3] = True

def dfs(x,y):
    global grid
    stack = []
    stack.append((x,y))
    visited = set()
    visited.add((x,y))
    sum = 0
    while stack:
        x,y = stack.pop()
        country = grid[x][y]
        population = country[0]
        up = country[1]
        down = country[2]
        left = country[3]
        right = country[4]
        sum += population
        # population, down, right = country
        if down and (x+1,y) not in visited:
            visited.add((x+1,y))
            stack.append((x+1,y))
        if up and (x-1,y) not in visited:
            visited.add((x-1,y))
            stack.append((x-1,y))
        if left and (x,y-1) not in visited:
            visited.add((x,y-1))
            stack.append((x,y-1))
        if right and (x,y+1) not in visited:
            visited.add((x,y+1))
            stack.append((x,y+1))
    for x,y in visited:
        grid[x][y][0] = sum//len(visited)
    return visited

cnt = 0
loop = True
while loop:
    visited = set()
    loop = False

    for i in range(n):
        for j in range(n):
            if (i,j) not in visited:
                new_visited = dfs(i,j)
                if len(new_visited) >= 2:
                    loop = True
                visited |= new_visited
    if loop:
        cnt += 1

    # grid[i][j] = 인구, 상,하,좌,우
    for i in range(n):
        for j in range(n):
            grid[i][j] = [grid[i][j][0],False,False,False,False]

    # 국경선 오픈
    for i in range(n):
        for j in range(n):
            if i < n-1 and (l <= abs(grid[i][j][0] - grid[i+1][j][0]) <= r):
                grid[i][j][2] = True
            if j < n-1 and (l <= abs(grid[i][j][0] - grid[i][j+1][0]) <= r):
                grid[i][j][4] = True
            if i > 0 and (l <= abs(grid[i][j][0] - grid[i-1][j][0]) <= r):
                grid[i][j][1] = True
            if j > 0 and (l <= abs(grid[i][j][0] - grid[i][j-1][0]) <= r):
                grid[i][j][3] = True
print(cnt)