from math import inf
import sys
from collections import defaultdict
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

n,m,k = map(int,input().split())
prices = [0]
prices.extend(list(map(int,input().split())))
parent = [i for i in range(n+1)]

my_set = defaultdict(set)
for i in range(1,n+1):
    my_set[i].add(i)

def find(target):
    if target == parent[target]:
        return target
    parent[target] = find(parent[target])
    return parent[target]

for _ in range(m):
    a,b = map(int,input().split())
    fa,fb = find(a),find(b)
    if fa != fb:
        if fa < fb:
            parent[fb] = fa
            my_set[fa]|=my_set[fb]
        else:
            parent[fa] = fb
            my_set[fb]|=my_set[fa]
    
res = 0
for i in range(1,n+1):
    if i == find(i) and prices[i] != -1:
        min_val = inf
        for num in my_set[i]:
            min_val = min(min_val,prices[num])
            prices[num] = -1
        res += min_val

if all(-1 == ele for ele in prices[1:]) and res <= k:
    print(res)
else:
    print("Oh no")