import sys
import heapq
from collections import deque,defaultdict

def dij(start):
    queue = list()
    queue.append((0,start))
    visited = set()
    dist = [sys.maxsize] * (n+1)
    while queue:
        cost,node = heapq.heappop(queue)
        if cost >= dist[node]:
            continue
        dist[node] = cost
        visited.add(node)

        for v,w in graph[node]:
            alt = cost + w
            if dist[v] > alt and v not in visited:
                heapq.heappush(queue,(alt,v))
    return dist

input = sys.stdin.readline
n = int(input().rstrip())
m = int(input().rstrip())

graph = defaultdict(list)
for _ in range(m):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))

for i in range(n):
    ret = dij(i+1)
    for j in range(len(ret)):
        if j ==0 :
            continue
        if ret[j] == sys.maxsize:
            print(0,end=" ")
        else:
            print(ret[j],end=" ")
    print()