import sys
from collections import defaultdict
def find(target):
    if target == parent[target]:
        return target
    parent[target] = find(parent[target])
    return parent[target]

def union(a,b):
    a,b = find(a),find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
input = sys.stdin.readline
n,m = map(int,input().split())
lines = []
for _ in range(m):
    x,y = map(int,input().split())
    lines.append((x,y))

parent = defaultdict(int)
for i in range(n):
    parent[i] = i
cnt = 1
for line in lines:
    x,y = line
    if find(x) != find(y):
        union(x,y)
    else:
        print(cnt)
        break
    cnt += 1
else:
    print(0)