import sys
from collections import defaultdict
def find(target):
    if target == parent[target]:
        return target
    parent[target] = find(parent[target])
    return parent[target]

input = sys.stdin.readline
n,m = map(int,input().split())
lines = []
for _ in range(m):
    x,y = map(int,input().split())
    lines.append((x,y))

parent = [i for i in range(n)]
for i in range(n):
    parent[i] = i

cnt = 1
for line in lines:
    x,y = line
    fx,fy = find(x),find(y)
    if  fx!=fy :
        if fx < fy:
            parent[fy] = fx
        else:
            parent[fx] = fy
    else:
        print(cnt)
        break
    cnt += 1
else:
    print(0)