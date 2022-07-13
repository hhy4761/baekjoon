import sys
import copy
from collections import deque,defaultdict
input = sys.stdin.readline

v = int(input().rstrip())
tree = defaultdict(list)
for i in range(1,v+1):
    inputs = list(map(int,input().split()))
    for k in range(1,len(inputs)-1,2):
        tree[inputs[0]].append((inputs[k],inputs[k+1]))
    
# 가장 먼 거리에 있는 노드 찾기
def dfs(start):
    global tree
    stack = []
    res = set()
    stack.append((start,0,set([start])))
    while stack:
        node,cost,visited = stack.pop()
        into_loop = False
        for n,w in tree[node]:
            if n not in visited:
                stack.append((n,cost+w,visited|set([n])))
                into_loop = True
        if not into_loop:
            res.add((cost,node))
    return max(res)
t = dfs(1)
u = dfs(t[1])
print(u[0])