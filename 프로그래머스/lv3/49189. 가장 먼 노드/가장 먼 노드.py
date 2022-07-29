from collections import defaultdict,deque

def solution(n, edge):
    answer = 0 
    graph = defaultdict(list)
    for u,v in edge:
        graph[u].append(v)
        graph[v].append(u)
    
    def dfs():
        queue = deque()
        queue.append((1,0))
        max_val = -1
        visited = [False for _ in range(n+1)]
        visited[1] = True
        while queue:
            node,count = queue.popleft()
            print(node,count)
            if max_val < count:
                max_val = count
                res = 1
            elif max_val == count:
                res += 1
            for v in graph[node]:
                if not visited[v]:
                    visited[v] = True
                    queue.append((v,count+1))
        return res
    
    return dfs()