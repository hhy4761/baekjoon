import sys
import heapq
from collections import defaultdict,deque

def is_conn(graph,start,end):
    queue = deque()
    queue.append(start)
    visited = []

    while queue:
        node = queue.popleft()
        if node in visited:
            continue
        if node == end:
            return True
        visited.append(node)
        for v,w, in graph[node]:
            if v not in visited:
                queue.append(v)
    return False

def dij(graph,start,end):
    queue = [(0,start)]
    distance = [sys.maxsize] * (N+1)
    distance[start] = 0

    while queue:
        price,node = heapq.heappop(queue)
        if distance[node] < price:
            continue
        if node == end:
            return price
        else:
            for v,w in graph[node]:
                alt = price+w
                if alt < distance[v]:
                    distance[v] = alt
                    heapq.heappush(queue,(alt,v))

input = sys.stdin.readline
N,E = map(int,input().split())
graph = defaultdict(list)
for _ in range(E):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))
    graph[v].append((u,w))
v1,v2 = map(int,input().split())

first_route = False
second_route = False

# 1 - v1 - v2 - N 경로 존재한다면
if is_conn(graph,1,v1) and is_conn(graph,v1,v2) and is_conn(graph,v2,N):
    a = dij(graph,1,v1)+dij(graph,v1,v2)+dij(graph,v2,N)
    first_route = True
# 1 - v2 - v1 - N 경로 존재한다면
if is_conn(graph,1,v2) and is_conn(graph,v2,v1) and is_conn(graph,v1,N):
    b = dij(graph,1,v2)+dij(graph,v2,v1)+dij(graph,v1,N)
    second_route = True

if first_route and second_route:
    print(min(a,b))
elif first_route:
    print(a)
elif second_route:
    print(b)
else:
    print(-1)