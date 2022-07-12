import sys
import copy
from collections import deque
input = sys.stdin.readline

dir = [(0,0),(-1,0),(-1,-1),(0,-1),(1,-1),(1,0),(1,1),(0,1),(-1,1)]

inputs = [list(map(int,input().split())) for _ in range(4)]
grid = [[0]*4 for _ in range(4)]

for i in range(4):
    for j in range(4):
        grid[i][j] = [inputs[i][2*j],inputs[i][2*j+1]]


def bfs():
    global grid
    q = deque()
    visited = set()
    ans = []
    q.append((0,0,visited,grid))
    
    while q:
        x,y,visited,g = q.popleft()
        shark = g[x][y]
        copy_visited = copy.copy(visited)
        copy_visited.add(shark[0])
        direction = dir[shark[1]]
        copy_grid = copy.deepcopy(g)
        copy_grid[x][y] = []
        copy_grid = fish_move(copy_grid,x,y)

        cnt = 0
        for i in range(4):
            x += direction[0]
            y += direction[1]
            if (0 <= x < 4) and (0 <= y < 4) and copy_grid[x][y]:
                q.append((x,y,copy_visited,copy_grid))
                cnt += 1
            elif i == 3 and cnt == 0:
                ans.append(copy_visited)
    return (ans)

def fish_move(graph,cur_shark_x,cur_shark_y):
    for num in range(1,17):
        for i in range(4):
            for j in range(4):
                is_find = False
                if graph[i][j] and graph[i][j][0] == num:
                    while True:
                        dir_num = graph[i][j][1]
                        x = i + dir[dir_num][0]
                        y = j + dir[dir_num][1]
                        if x < 0 or x >= 4 or y < 0 or y >= 4 or (x==cur_shark_x and y==cur_shark_y):
                            if dir_num < 8:
                                graph[i][j][1] = dir_num + 1
                            else:
                                graph[i][j][1] = 1
                        elif not graph[x][y]:
                            graph[x][y] = graph[i][j]
                            graph[i][j] = []
                            is_find = True
                            break
                        elif graph[x][y]:
                            temp = graph[x][y]
                            graph[x][y] = graph[i][j]
                            graph[i][j] = temp
                            is_find = True
                            break
                if is_find:
                    break
            if is_find:
                break
        
        # print(i,j,num)
        # for v in graph:
        #     print(v)
        # time.sleep(1)        
    return graph
res = bfs()
max_val = 0
for r in res:
    max_val = max(max_val,sum(r))
print(max_val)