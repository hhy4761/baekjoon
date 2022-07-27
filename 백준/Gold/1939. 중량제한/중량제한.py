import sys,heapq
from collections import defaultdict,deque
input = sys.stdin.readline
n,m = map(int,input().split())
graph = defaultdict(list)
for _ in range(m):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))
    graph[v].append((u,w))

start,end = map(int,input().split())

def bfs(start,end):
    q = []
    q.append((0,start))
    visited = [-1 for _ in range(n+1)]

    while q:
        weight,node = heapq.heappop(q)
        weight = -weight
        if node == end:
            return weight
        for v,w in graph[node]:
            if visited[v] < w:
                visited[v] = w
                if node == start:
                    heapq.heappush(q,(-w,v))
                else:
                    if w < weight:
                        heapq.heappush(q,(-w,v))
                    else:
                        heapq.heappush(q,(-weight,v))
print(bfs(start,end))