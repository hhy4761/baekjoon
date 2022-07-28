import sys
from collections import defaultdict
sys.setrecursionlimit(100000)

def find(target):
    if target == parent[target]:
        return target
    parent[target] = find(parent[target])
    return parent[target]

def union(a,b):
    a = find(a)
    b = find(b)

    if a!=b:
        parent[a] = b
        friends[b] += friends[a]
    print(friends[b])

t = int(input().rstrip())
for _ in range(t):
    parent = defaultdict(str)
    friends = defaultdict(int)
    f = int(input().rstrip())
    for _ in range(f):
        a,b = map(str,input().split())
        if a not in parent:
            parent[a] = a
            friends[a] = 1
        if b not in parent:
            parent[b] = b
            friends[b] = 1
        union(a,b)
    parent.clear()
