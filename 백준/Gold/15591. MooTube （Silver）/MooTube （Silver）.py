import sys
from collections import defaultdict,deque
def dfs(start,k):
    queue = deque()
    visited = set()
    queue.append((start,float(sys.maxsize)))
    visited.add(start)
    cnt = 0
    while queue:
        node,usado = queue.popleft()

        if node != start and usado >= k :
            cnt += 1

        for v,w in graph[node]:
            if v not in visited:
                visited.add(v)
                if w < usado:
                    queue.append((v,w))
                else:
                    queue.append((v,usado))
                
                
    return cnt

input = sys.stdin.readline
n,q = map(int,input().split())
graph = defaultdict(list)
for _ in range(n-1):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))
    graph[v].append((u,w))

for _ in range(q):
    k,start = map(int,input().split())
    print(dfs(start,k))