import sys
from collections import defaultdict

def bellman_ford():
    # for start in range(1,V+1):
    dist = [sys.maxsize] * (V+1)
    dist[1] = 0
    for i in range(V):
        for u,v,w in graph:
            if dist[v] > dist[u] + w:
                if i == V-1:
                    return True
                dist[v] = dist[u] + w
    return False

input = sys.stdin.readline
N = int(input().rstrip())
for i in range(N):
    # Vertex, Edge, Wormhole
    V,E,W = map(int,input().split()) 
    graph =[]
    for _ in range(E):
        u,v,w = map(int,input().split())
        graph.append((u,v,w))
        graph.append((v,u,w))
    for _ in range(W):
        u,v,w = map(int,input().split())
        graph.append((u,v,-w))
    result = bellman_ford()
    if result:
        print("YES")
    else:
        print("NO")

