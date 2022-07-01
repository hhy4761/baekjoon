import sys
import heapq
import time
from collections import defaultdict

input=sys.stdin.readline
v,e = map(int,input().split())

graph = defaultdict(list)
heap = []
visited = set()
for i in range(e):
    start,end,w = map(int,input().split())
    # heapq.heappush(heap,(w,start,end))
    graph[start].append((w,end))
    graph[end].append((w,start))

sum = 0

start = 1
while len(visited) != v:
    visited.add(start)
    for i in range(len(graph[start])):
        heapq.heappush(heap,graph[start][i])
    graph[start] = []
    w,e = heapq.heappop(heap)
    if e in visited:
        continue
    sum += w
    start = e

print(sum)