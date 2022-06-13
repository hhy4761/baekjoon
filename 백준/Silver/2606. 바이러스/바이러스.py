from collections import deque
def bfs(graph,start):
    queue = deque()
    visited = set()
    queue.append(start)

    while queue:
        x = queue.popleft()
        if x in visited:
            continue
        visited.add(x)
        for g in graph[x]:
            queue.append(g)
    return len(visited)

# Make a graph
v = int(input())
e = int(input())
graph = {}
for i in range(v):
    graph[i+1] = set()
for _ in range(e):
    f,t = map(int,input().split())
    graph[f].add(t)
    graph[t].add(f)
print(bfs(graph,1)-1)