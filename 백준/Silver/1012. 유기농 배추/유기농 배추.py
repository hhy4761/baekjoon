from collections import deque

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(arr,a,b,m,n):
    queue = deque()
    queue.append((a,b))
    arr[a][b] = 0
    
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= m or nx < 0 or ny >= n or ny <0:
                continue
            if arr[nx][ny] == 1:
                arr[nx][ny] = 0
                queue.append((nx,ny))
    return
               
a = int(input())
for i in range(a):
    m,n,k = map(int, input().split())
    arr = [[0]*n for _ in range(m)]
    for i in range(k):
        x,y = map(int,input().split())
        arr[x][y] = 1
    count = 0
    for a in range(m):
        for b in range(n):
            if arr[a][b] == 1:
                bfs(arr,a,b,m,n)
                count += 1
    print(count)
    