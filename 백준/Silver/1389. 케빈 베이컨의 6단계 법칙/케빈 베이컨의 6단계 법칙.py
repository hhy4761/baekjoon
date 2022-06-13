from collections import deque

def bfs(graph,start):
    queue = deque()
    visited = []
    count = 0
    queue.append((start,count))
    ans = 0
    while queue:
        start,count = queue.popleft()
        if start in visited:
            continue
        visited.append(start)
        ans += count
        count += 1
        for g in graph[start]:
            queue.append((g,count))
    return ans

v,e = map(int,input().split())
graph = {}
answer = []
for i in range(v):
    graph[i+1] = set()

for i in range(e):
    start,end = map(int,input().split())
    graph[start].add(end)
    graph[end].add(start)

for i in range(v):
    answer.append(bfs(graph,i+1))

print(answer.index(min(answer))+1)