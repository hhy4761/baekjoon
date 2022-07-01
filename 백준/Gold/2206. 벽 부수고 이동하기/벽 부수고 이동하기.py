import sys
from collections import deque,defaultdict

input = sys.stdin.readline

dx = [0,0,1,-1]
dy = [1,-1,0,0]
N,M = map(int,input().split())

# Make a graph
graph = [[0]*M for _ in range(N)]
for i in range(N):
    graph[i] = list(map(int,list(input().rstrip())))

def bfs(graph):
    queue = deque()
    count = 1
    queue.append((0,0,False,count))
    # visit = defaultdict(int)
    visit = set()

    while queue:
        x,y,is_break,count = queue.popleft()

        if x == N-1 and y == M-1:
            return (count)

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx >= N or nx < 0 or ny>=M or ny <0:
                continue
            # if visit[(nx,ny,is_break)] == 0:
            if ((nx,ny,is_break)) not in visit:
                if graph[nx][ny] == 0:
                    queue.append((nx,ny,is_break,count+1))
                    # visit[(nx,ny,is_break)] = 1
                    visit.add((nx,ny,is_break))
                elif graph[nx][ny] == 1 and not is_break:
                    queue.append((nx,ny,True,count+1))
                    # visit[(nx,ny,is_break)] = 1
                    visit.add((nx,ny,is_break))
                else:
                    continue
    return -1

print(bfs(graph))

            