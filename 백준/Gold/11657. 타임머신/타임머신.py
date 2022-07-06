import sys
from collections import defaultdict

def bellman_ford():
    dist = [sys.maxsize] * (V+1)
    dist[1] = 0
    for i in range(1,V+1):
        for u,v,w in graph:
            if dist[u] != sys.maxsize and dist[v] > dist[u] + w:
                if i == V:
                    return -1
                dist[v] = dist[u] + w
    return dist

input = sys.stdin.readline
V,E = map(int,input().split())
graph =[]
for i in range(E):
    u,v,w = map(int,input().split())
    graph.append((u,v,w))

result = bellman_ford()
if result != -1:
    for i in range(2,V+1):
        if result[i] == sys.maxsize:
            print(-1)
        else:
            print(result[i])
else:
    print(-1)