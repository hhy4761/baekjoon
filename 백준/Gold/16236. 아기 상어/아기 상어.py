import sys
import time
from collections import deque

input = sys.stdin.readline
n = int(input().rstrip())

graph = [[0]* n for _ in range(n)]
for i in range(n):
    graph[i] = list(map(int,input().split()))
    if 9 in graph[i]:
        start = (i,graph[i].index(9))

dx = [-1,0,0,1]
dy = [0,-1,1,0]

def check_prey(next_graph,size):
    for i in range(n):
        for j in range(n):
            if next_graph[i][j] != 0 and next_graph[i][j] < size:
                return True
    return False

def find_closest_prey(start,cur_size):
    global graph
    x,y = start
    t = 0
    visited = set([(x,y)])
    q = deque([(x,y,cur_size,t)])
    ans = list()
    dist = sys.maxsize
    while q:
        x,y,cur_size,t = q.popleft()
        if not check_prey(graph,cur_size):
            return ans
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= n or nx < 0 or ny >= n or ny < 0:
                continue
            if t+1 <= dist and (graph[nx][ny] != 0 and graph[nx][ny] < cur_size):
                if (nx,ny,t+1) not in ans:
                    ans.append((nx,ny,t+1))
                    dist = t+1
            elif t+1 < dist and (graph[nx][ny] == cur_size or graph[nx][ny] == 0):
                if (nx,ny) not in visited:
                    visited.add((nx,ny))
                    q.append((nx,ny,cur_size,t+1))
    return sorted(ans)

def bfs(start):
    global graph
    cur_size = 2
    feed_count = 0
    t = 0
    x,y = start
    graph[x][y] = 0

    preys = find_closest_prey(start,cur_size)
    while preys:
        cur_x,cur_y,dist = preys[0]
        graph[cur_x][cur_y] = 0
        t += dist
        feed_count += 1
        if cur_size == feed_count:
            cur_size += 1
            feed_count = 0
        preys = find_closest_prey((cur_x,cur_y),cur_size)
    return t

print(bfs(start))