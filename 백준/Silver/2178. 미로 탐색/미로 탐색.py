from collections import deque
dx=[0,0,1,-1]
dy=[1,-1,0,0]
def bfs(graph,x,y):
    queue = deque()
    visited = []
    ans = [[0]*M for i in range(N)]
    queue.append((x,y))

    while queue:
        x,y = queue.popleft()
        if (x,y) in visited:
            continue
        visited.append((x,y))
        if x == N-1 and y == M-1:
            return ans
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # print(nx,ny)

            if nx >= N or nx < 0 or ny >= M or ny < 0:
                continue
            if graph[nx][ny] == 0:
                continue
            ans[nx][ny] = ans[x][y] + 1
            queue.append((nx,ny))

N,M = map(int,input().split())
graph = [[0]*M for i in range(N)]
for i in range(N):
    graph[i] = list(map(int,list(input())))
a = bfs(graph,0,0)
print(a[N-1][M-1]+1)