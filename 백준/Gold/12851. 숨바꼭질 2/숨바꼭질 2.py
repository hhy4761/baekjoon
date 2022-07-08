import sys
from collections import deque

input = sys.stdin.readline
n,k = map(int,input().split())
dist = [[-1,0] for _ in range(100001)]
def bfs(n):
    global dist
    q = deque()
    q.append((n))
    dist[n][0] = 0
    dist[n][1] = 1
    while q :
        cur = q.popleft()

        for next in [cur-1, cur+1 , 2*cur]:
            if 0 <= next <= 100000:
                if dist[next][0] == -1: # 방문기록 x
                    dist[next][0] = dist[cur][0]+1
                    dist[next][1] = dist[cur][1]
                    q.append(next)

                elif dist[next][0] != -1: # 방문기록 o
                    if dist[next][0] == dist[cur][0] + 1:
                        dist[next][1] += dist[cur][1]

bfs(n)
print(dist[k][0])
print(dist[k][1])