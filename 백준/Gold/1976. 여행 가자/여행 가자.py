import sys
from collections import defaultdict
sys.setrecursionlimit(100000)

input = sys.stdin.readline
n = int(input().rstrip())
m = int(input().rstrip())
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
        
for i in range(1,n+1):
    conn = list(map(int,input().split()))
    for j in range(len(conn)):
        if conn[j] == 1:
            union(i,j+1)
            
plan = list(map(int,input().split()))

root = find(plan[0])
for p in plan:
    if root != find(p):
        print("NO")
        break
else:
    print("YES")