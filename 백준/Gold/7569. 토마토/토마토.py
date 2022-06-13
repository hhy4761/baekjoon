import sys
from collections import deque
input = sys.stdin.readline

dx = [0,0,1,-1]
dy = [1,-1,0,0]
dz = [1,-1]

def bfs(graph,ripe_index):
    queue = deque()
    is_finish = False
    for i,j,k in ripe_index:
        queue.append((i,j,k))
    while queue:
        i,j,k = queue.popleft()
        # case1 : i is not fixed
        for n in range(2):
            nz = i + dz[n]

            if nz >= H or nz < 0:
                continue
            elif graph[nz][j][k] == 0:
                graph[nz][j][k] = graph[i][j][k] + 1
                queue.append((nz,j,k))

        # case2 : i is fixed
        for n in range(4):
            nx = j + dx[n]
            ny = k + dy[n]

            if nx >= M or nx < 0 or ny >= N or ny < 0:
                continue
            elif graph[i][nx][ny] == 0:
                graph[i][nx][ny] = graph[i][j][k] + 1
                queue.append((i,nx,ny))
    for i in range(H):
        if any(0 in g for g in graph[i]):
            break
        if i == H-1:
            is_finish = True
    if is_finish:
        max_val = 0
        for i in range(H):
            max_val = max(max_val, max(map(max,graph[i])))
        return max_val-1
    else:
        return -1


# Make graph
N,M,H = map(int,input().split())
graph = [[[0]*N for i in range(M)] for j in range(H)]
ripe_index = []
for i in range(H):
    for j in range(M):
        graph[i][j] = list(map(int,input().split()))
        
        # Find ripe tomato index for starting point
        if 1 in graph[i][j]:
            res = [index for index, value in enumerate(graph[i][j]) if value == 1]
            for k in res:
                ripe_index.append((i,j,k))

print(bfs(graph,ripe_index))