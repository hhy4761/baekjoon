def dfs(edges,start):
    discoverd =  []
    stack = [start]
    while stack:
        v = stack.pop()
        if v not in discoverd:
            discoverd.append(v)
            for w in edges[v]:
                stack.append(w)
    return discoverd

def bfs(edges,start):
    discoverd = [start]
    queue = [start]
    while queue:
        v = queue.pop(0)
        for w in edges[v]:
            if not w in discoverd:
                discoverd.append(w)
                queue.append(w)
    return discoverd

num_vertex, num_edge, start_vertex = map(int, input().split())

edges = {}
for i in range(num_vertex):
    edges[i+1] = []
for i in range(num_edge):
    start,end = map(int,input().split())
    edges[start].append(end)
    edges[end].append(start)
# edges 역순으로 정렬
for key in edges:
    edges[key].sort(reverse=True)
dfs_list = dfs(edges,start_vertex)

for key in edges:
    edges[key].sort()
bfs_list = bfs(edges,start_vertex)

for e in dfs_list:
    print(e,end=" ")
print()
for e in bfs_list:
    print(e,end=" ")