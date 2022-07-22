import sys
input = sys.stdin.readline

r,c,t = map(int,input().split())
grid = [[] for _ in range(r)]

find_upper = False
for i in range(r):
    grid[i] = list(map(int,input().split()))
    if -1 in grid[i] and not find_upper:
        circulation_upper_pos = (i,grid[i].index(-1))
        find_upper = True
    elif -1 in grid[i] and find_upper:
        circulation_lower_pos = (i,grid[i].index(-1))
        
dx = [0,0,1,-1]
dy = [1,-1,0,0]

def spread_dust(x,y):
    global grid,add_list
    cur_dust = grid[x][y]
    spread_amount = grid[x][y]//5
    cnt = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= r or ny < 0 or ny >= c or grid[nx][ny] == -1:
            continue
        add_list.append((nx,ny,spread_amount))
        cnt += 1
    add_list.append((x,y,-spread_amount*cnt))
    

def circulate(upper,lower):
    # upper position of circulation
    x1,y1 = upper
    x,y = x1,y1
    while y != 0:
        if grid[x][y] != -1:
            grid[x][y] = grid[x][y-1]
        y -= 1
    while x != 0:
        if grid[x][y] != -1:
            grid[x][y] = grid[x-1][y]
        x -= 1
    while y != c-1:
        grid[x][y] = grid[x][y+1]
        y+=1
    while x != x1:
        grid[x][y] = grid[x+1][y]
        x+=1
    while y!= y1:
        if grid[x][y-1] != -1:
            grid[x][y] = grid[x][y-1]
        else:
            grid[x][y] = 0
        # print(x,y,grid[x][y])
        y -= 1
    # lower position of circulation
    x2,y2 = lower
    x,y = x2,y2
    while y != 0:
        if grid[x][y] != -1:
            grid[x][y] = grid[x][y-1]
        y -= 1
    while x != r-1:
        if grid[x][y] != -1:
            grid[x][y] = grid[x+1][y]
        x += 1
    while y != c-1:
        grid[x][y] = grid[x][y+1]
        y+=1
    while x != x2:
        grid[x][y] = grid[x-1][y]
        x-=1
    while y!= y2:
        if grid[x][y-1] != -1:
            grid[x][y] = grid[x][y-1]
        else:
            grid[x][y] = 0
        y -= 1

for _ in range(t):
    spread_list = []
    add_list = []
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] > 0 :
                spread_list.append((i,j))
    for x,y in spread_list:
        spread_dust(x,y)
    for x,y,val in add_list:
        grid[x][y] += val

    circulate(circulation_upper_pos,circulation_lower_pos)

ans = 0
for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] > 0 :
            ans += grid[i][j]
print(ans)