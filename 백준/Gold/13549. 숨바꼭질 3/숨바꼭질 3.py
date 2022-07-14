import sys
from collections import deque
input = sys.stdin.readline

n,k = map(int,input().split())
visited = [[0] * 2 for _ in range(100001)]
def bfs():
    global n,k,visited
    q = deque()
    q.append((n,0))

    while q:
        n,count = q.popleft()
        if n == k:
            print(visited[k][1])
            break
        for x in [2*n,n+1,n-1]:
            if 0<= x<= 100000: # 방문 x
                if x != 2*n:
                    if visited[x][0] == 0:
                        visited[x][0] = 1
                        visited[x][1] = count+1
                        q.append((x,count+1))
                    elif visited[x][1] > count+1:
                        visited[x][1] = count+1
                        q.append((x,count+1))
                else:
                    if visited[x][0] == 0:
                        visited[x][0] = 1
                        visited[x][1] = count
                        q.appendleft((x,count))
                    elif visited[x][1] > count:
                        visited[x][1] = count
                        q.appendleft((x,count))
            
bfs()