import sys
from collections import defaultdict
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def find(target):
    if target == parent[target]:
        return target
    parent[target] = find(parent[target])
    return parent[target]

def union(a,b):
    a,b = find(a),find(b)
    if a == b or visited[a] or visited[b]:
        return False
    if a < b:
        parent[b] = a
        sets[a]|=sets[b]
    else:
        parent[a] = b
        sets[b]|=sets[a]
    return True

case = 1
while True:
    n,m = map(int,input().split())
    
    if n==0 and m==0:
        break
    parent = [i for i in range(n+1)]
    visited = [False for _ in range(n+1)]
    sets = defaultdict(set)
    for i in range(1,n+1):
        sets[i].add(i)
    for _ in range(m):
        x,y = map(int,input().split())
        if not union(x,y):
            for s in sets[find(x)]|sets[find(y)]:
                visited[s] = True
    cnt = 0
    for i in range(1,n+1):
        if not visited[i] and parent[i] == i:
            for s in sets[i]:
                visited[s] = True
            cnt += 1
    if cnt == 0:
        print(f"Case {case}: No trees.")
    elif cnt ==1:
        print(f"Case {case}: There is one tree.")
    else:
        print(f"Case {case}: A forest of {cnt} trees.")
    case += 1