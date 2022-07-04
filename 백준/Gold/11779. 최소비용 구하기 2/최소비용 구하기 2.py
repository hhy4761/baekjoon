import sys
import heapq
from collections import defaultdict
def bfs(start,end):
    queue = []
    heapq.heappush(queue,(0,start,[start]))
    visited = set()
    while queue:
        cost,node,route = heapq.heappop(queue)
        if node in visited:
            continue
        if node == end:
            return cost,len(route),route
        visited.add(node)
        for v,w in graph[node]:
            alt = cost + w
            if v not in visited:
                heapq.heappush(queue,(alt,v,route+[v]))

input = sys.stdin.readline
n = int(input().rstrip())
m = int(input().rstrip())
graph = defaultdict(list)
for _ in range(m):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))
start,end = map(int,input().split())

ans = bfs(start,end)
print(ans[0])
print(ans[1])
for ele in ans[2]:
    print(ele,end=" ")