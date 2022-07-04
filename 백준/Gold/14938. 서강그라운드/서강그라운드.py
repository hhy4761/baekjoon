import sys
import heapq
from collections import defaultdict

def bfs(start,m):
    queue = []
    visited = set()
    heapq.heappush(queue,(0,start))

    while queue:
        cost,node = heapq.heappop(queue)
        if cost > m:
            continue
        visited.add(node)
        for v,w in graph[node]:
            if v not in visited:
                alt = cost + w
                heapq.heappush(queue,(alt,v))
    return visited

input = sys.stdin.readline
n,m,r = map(int,input().split())
item = [0]
item += list(map(int,input().split()))
graph = defaultdict(list)
for _ in range(r):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))
    graph[v].append((u,w))
max_val = 0
for i in range(n):
    regions = bfs(i+1,m)
    sum = 0
    for region in regions:
        sum += item[region]
    max_val = max(max_val,sum)
print(max_val)
