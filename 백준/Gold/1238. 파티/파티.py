import sys
import heapq
from collections import defaultdict
from collections import Counter

def sol(graph,start,end):
    queue = [(0,start)]
    visited= set()

    while queue:
        price,node = heapq.heappop(queue)
        if node == end:
            return price
        if node in visited:
            continue
        visited.add(node)
        for v,w in graph[node]:
            if v not in visited:
                alt = price + w
                heapq.heappush(queue,(alt,v))

input = sys.stdin.readline
N,M,X = map(int,input().split())
graph = defaultdict(list)
for i in range(M):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))

first = defaultdict(int)
second = defaultdict(int)
for i in range(1,N+1):
    first[i] = sol(graph,i,X)
    second[i] = sol(graph,X,i)

ans = max((Counter(first)+Counter(second)).values())
print(ans)