import sys
import copy
from collections import deque
input = sys.stdin.readline
dx = [0,0,1,-1]
dy = [1,-1,0,0]

def normal_bfs(graph,x,y):
    queue = deque()
    queue.append((x,y))
    visited = set()
    if graph[x][y] == '#':
        return False

    while queue:
        x,y = queue.popleft()
        if graph[x][y] == 'R':
            color = 'R'
        elif graph[x][y] == 'G':
            color = 'G'
        elif graph[x][y] == 'B':
            color = 'B'
        else:
            continue
        
        graph[x][y] = '#'
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= N or nx < 0 or ny >= N or ny < 0:
                continue
            if (nx,ny) in visited:
                continue
            if color == graph[nx][ny]:
                visited.add((nx,ny))
                queue.append((nx,ny))
            else:
                continue
            
    return True

def blind_bfs(graph,x,y):
    queue = deque()
    queue.append((x,y))
    visited = set()
    if graph[x][y] == '#':
        return False

    while queue:
        x,y = queue.popleft()
        if graph[x][y] == 'R':
            color = 'R'
        elif graph[x][y] == 'G':
            color = 'G'
        elif graph[x][y] == 'B':
            color = 'B'
        else:
            continue
        
        graph[x][y] = '#'
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= N or nx < 0 or ny >= N or ny < 0:
                continue
            if (nx,ny) in visited:
                continue
            if color == graph[nx][ny]:
                visited.add((nx,ny))
                queue.append((nx,ny))
            elif color == 'R' and graph[nx][ny] == 'G':
                visited.add((nx,ny))
                queue.append((nx,ny))
            elif color == 'G' and graph[nx][ny] == 'R':
                visited.add((nx,ny))
                queue.append((nx,ny))
            else:
                continue
            
    return True
    


N = int(input().rstrip())
graph = [[0]*N for i in range(N)]
for i in range(N):
    graph[i] = list(input().rstrip())

normal_graph = copy.deepcopy(graph)
blind_graph = copy.deepcopy(graph)

normal_count = 0
blind_count = 0
for i in range(N):
    for j in range(N):
        if normal_bfs(normal_graph,i,j):
            normal_count+=1
        if blind_bfs(blind_graph,i,j):
            blind_count+=1

print(normal_count,blind_count)