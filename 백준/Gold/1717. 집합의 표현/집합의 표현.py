import sys
from collections import defaultdict
sys.setrecursionlimit(100000)

input = sys.stdin.readline
n,m = map(int,input().split())
parent = defaultdict(int)

for i in range(1,n+1):
    parent[i] = i

def find(target):
    if target == parent[target]:
        return target
    
    parent[target] = find(parent[target])
    return parent[target]

def union(a,b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

for _ in range(m):
    op,a,b = map(int,input().split())
    if op == 0:
        union(a,b)
    else:
        if find(a) == find(b):
            print("YES")
        else:
            print("NO")