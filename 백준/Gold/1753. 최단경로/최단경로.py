import sys
import heapq
from collections import defaultdict

input = sys.stdin.readline

def dijk(graph,start):
    queue = [(0,start)]
    visited = set()
    ans = [0 for i in range(V+1)]

    while queue:
        price,node = heapq.heappop(queue)
        if node in visited:
            continue
        visited.add(node)
        ans[node] = price
        for v,w in graph[node]:
            if v not in visited:
                alt = price + w
                heapq.heappush(queue,(alt,v))
    return (ans)

V,E = map(int,input().split())
start = int(input())
graph = defaultdict(list)
for i in range(E):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))
ans = dijk(graph,start)
for i in range(1,len(ans)):
    if i != start:
        if ans[i] ==0:
            print("INF")
        else:
            print(ans[i])
    else:
        print(ans[i])

