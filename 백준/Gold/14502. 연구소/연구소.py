import sys
import time
import copy
from collections import deque
from itertools import combinations
def dfs(x,y):
    stack = []
    route = list()
    visited = set()
    route.append((x,y))
    stack.append((x,y,route))
    visited.add((x,y,route))
    arr = []

    while stack:
        x,y,route = stack.pop()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= N or nx < 0 or ny >= M or ny < 0:
                continue
            if graph[nx][ny] == 0 and len(route) < 3 and (nx,ny,route) not in visited:
                print(stack)
                time.sleep(1)
                stack.append((nx,ny,route))
                route.add((nx,ny))
                if len(route) == 3:
                    arr.append(route)
                else:
                    stack.append((nx,ny,route))

def spread_virus(graph,arr):
    queue = deque()
    visited = set()
    for x,y in arr:
        queue.append((x,y))
        visited.add((x,y))
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >=N or nx < 0 or ny >= M or ny < 0:
                continue
            if graph[nx][ny] == 0 and (nx,ny) not in visited:
                graph[nx][ny] = 2
                queue.append((nx,ny))
                visited.add((nx,ny))

    safe_area = 0
    for i in range(N):
        safe_area += graph[i].count(0)
    return safe_area
            

input = sys.stdin.readline

dx = [0,0,1,-1]
dy = [1,-1,0,0]
N,M = map(int,input().split())

# Make a graph
graph = [[0]*M for _ in range(N)]
for i in range(N):
    graph[i] = list(map(int,input().split()))

# Insert coordinates of virus into arr 
arr = []
arr2 = []
for i in range(N):
    for j in range(M):
        if graph[i][j] == 2:
            arr.append((i,j))
        elif graph[i][j] == 0:
            arr2.append((i,j))

# print(spread_virus(arr))
# print(dfs(0,0))
comb = list(combinations(arr2,3))
max_val = 0
for i in range(len(comb)):
    copy_graph = copy.deepcopy(graph)
    for x,y in comb[i]:
        copy_graph[x][y] = 1
    max_val = max(max_val,spread_virus(copy_graph,arr))
print(max_val)