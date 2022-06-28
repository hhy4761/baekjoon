import sys
import heapq
from collections import defaultdict

input = sys.stdin.readline
N = int(input().rstrip())
M = int(input().rstrip())
graph = defaultdict(list)
for i in range(M):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))

start,end = map(int,input().split())

queue = [(0,start)]
visited = set()

while queue:
    price,node = heapq.heappop(queue)
    if node in visited:
        continue
    visited.add(node)
    if node == end:
        print(price)
        break
    else:
        for v,w in graph[node]:
            if v not in visited:
                alt = price+w
                heapq.heappush(queue,(alt,v))