import sys
from collections import deque
input = sys.stdin.readline
dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(graph):
    queue = set()
    queue.add((0,0,graph[0][0]))
    max_val = 0

    while queue:
        x,y,route = queue.pop()
        max_val = max(max_val,len(route))   
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= R or nx < 0 or ny >= C or ny < 0:
                continue
            if graph[nx][ny] not in route:
                queue.add((nx,ny,route+graph[nx][ny]))
    print(max_val)

def dfs(graph):
    stack = deque()
    stack.append((0,0,graph[0][0]))
    max_val = 0

    while stack:
        x,y,route = stack.pop()
        max_val = max(max_val,len(route))   
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= R or nx < 0 or ny >= C or ny < 0:
                continue
            if graph[nx][ny] not in route:
                stack.append((nx,ny,route+graph[nx][ny]))
    print(max_val)


R,C = map(int,input().split())
graph = [[0]*C for i in range(R)]
for i in range(R):
    graph[i] = list(input().rstrip())

dfs(graph)