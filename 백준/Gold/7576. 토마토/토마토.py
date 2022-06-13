from collections import deque

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(graph,ripe_index):
    queue = deque()
    visited = []
    for index in ripe_index:
        queue.append(index)
    is_finish = False
    while queue:
        x,y = queue.popleft()
        # if (x,y) in visited:
        #     continue
        # visited.append((x,y))

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= M or nx < 0 or ny >= N or ny < 0:
                continue
            elif graph[nx][ny] == -1:
                continue
            elif graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx,ny))
                
    # If there are 0's in graph, It is not finished.
    if all(0 not in g for g in graph):
        is_finish = True
    if is_finish:
        return max(map(max,graph))-1
    else:
        return -1

# Make graph
N,M = map(int,input().split())
graph = [[0]*N for i in range(M)]
ripe_index = []
for i in range(M):
    graph[i] = list(map(int,list(input().split())))
    if 1 in graph[i]:
        res = [i for i , value in enumerate(graph[i]) if value == 1]
        for j in res:
            ripe_index.append((i,j))

print(bfs(graph,ripe_index))