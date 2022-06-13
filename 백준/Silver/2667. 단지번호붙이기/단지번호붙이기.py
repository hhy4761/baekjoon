from collections import deque
import sys
input = sys.stdin.readline

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(graph,i,j):
    queue = deque()
    visited = []
    queue.append((i,j))

    while queue:
        i,j = queue.popleft()
        if (i,j) in visited:
            continue
        visited.append((i,j))
        for n in range(4):
            nx = i + dx[n]
            ny = j + dy[n]
            if nx >= N or nx < 0 or ny >= N or ny < 0:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx,ny))
    return visited

# Make a graph
N = int(input().rstrip())
graph = [[0]*N for i in range(N)]
for i in range(N):
    graph[i] = list(map(int,list(input().rstrip())))

ans = []
for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            ans.append(len(bfs(graph,i,j)))
ans = sorted(ans)
print(len(ans))
for a in ans:
    print(a)