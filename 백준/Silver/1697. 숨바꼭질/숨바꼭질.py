from collections import deque
def bfs(n,k):
    queue = deque()
    count = 0 
    visited= set()
    queue.append((n,count))

    while queue:
        x,count = queue.popleft()
        if x in visited:
            continue
        visited.add(x)
        if x == k:
            return count
        count += 1
        if x-1 >= 0:
            queue.append((x-1,count))
        if x+1 <= 100000:
            queue.append((x+1,count))
        if 2*x <= 100000:
            queue.append((2*x,count))
            

n,k = map(int,input().split())
print(bfs(n,k))