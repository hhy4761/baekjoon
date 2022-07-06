import sys
import copy
from collections import deque

input = sys.stdin.readline
n = int(input().rstrip())
grid = [[0]*n for _ in range(n)]

for i in range(n):
    grid[i] = list(map(int,input().split()))
def update(g,dir):
    items = deque()
    ret = deque()
    if dir == 0:
        for i in range(len(g[0])):
            for j in range(len(g)):
                if g[j][i] != 0: 
                    items.append(g[j][i])
            while items:
                if len(items) >= 2:
                    first = items.popleft()
                    second = items.popleft()
                    if first == second: 
                        ret.append(2*first)
                    else: 
                        ret.append(first)
                        items.appendleft(second)
                else: # len(items) == 1
                    ret.append(items.popleft()) 
            for j in range(len(g)):
                if ret: 
                    g[j][i] = ret.popleft()
                else: 
                    g[j][i] = 0
    elif dir == 1:
        for i in range(len(g)):
            for j in reversed(range(len(g[0]))):
                if g[i][j] != 0: 
                    items.append(g[i][j])
            while items:
                if len(items) >= 2:
                    first = items.popleft()
                    second = items.popleft()
                    if first == second: 
                        ret.append(2*first)
                    else: 
                        ret.append(first)
                        items.appendleft(second)
                else: # len(items) == 1
                    ret.append(items.popleft()) 
            for j in reversed(range(len(g[0]))):
                if ret: 
                    g[i][j] = ret.popleft()
                else: 
                    g[i][j] = 0
    elif dir == 2:
        for i in range(len(g[0])):
            for j in reversed(range(len(g))):
                if g[j][i] != 0: 
                    items.append(g[j][i])
            while items:
                if len(items) >= 2:
                    first = items.popleft()
                    second = items.popleft()
                    if first == second: 
                        ret.append(2*first)
                    else: 
                        ret.append(first)
                        items.appendleft(second)
                else: # len(items) == 1
                    ret.append(items.popleft()) 
            for j in reversed(range(len(g))):
                if ret: 
                    g[j][i] = ret.popleft()
                else: 
                    g[j][i] = 0
    elif dir == 3:
        for i in range(len(g)):
            for j in range(len(g[0])):
                if g[i][j] != 0: 
                    items.append(g[i][j])
            while items:
                if len(items) >= 2:
                    first = items.popleft()
                    second = items.popleft()
                    if first == second: 
                        ret.append(2*first)
                    else: 
                        ret.append(first)
                        items.appendleft(second)
                else: # len(items) == 1
                    ret.append(items.popleft()) 
            for j in range(len(g[0])):
                if ret: 
                    g[i][j] = ret.popleft()
                else: 
                    g[i][j] = 0
    return g

def dfs():
    global grid
    stack = []
    ans = []
    count = 0
    for dir in range(4): # dir: {0:up,1:right,2:down,3:left}
        g = copy.deepcopy(grid)
        stack.append((g,dir,count))

    while stack:
        g,dir,count = stack.pop()
        g = update(g,dir)
        count += 1
        if count == 5:
            max_val = 0
            for i in range(len(g)):
                for j in range(len(g[i])):
                    max_val = max(max_val,g[i][j])
            ans.append(max_val)
        else:
            for dir in range(4):
                copy_g = copy.deepcopy(g)
                stack.append((copy_g,dir,count))
    return max(ans)

print(dfs())