import sys

input = sys.stdin.readline
n,m = map(int,input().split())
trees = list(map(int,input().split()))
trees.sort()
start,end = 1,max(trees)
while start <= end:
    mid = (end+start)//2
    total = 0

    for tree in trees:
        if tree > mid:
            total += tree-mid
    if total >= m:
        start = mid+1
    else:
        end = mid-1
print(end)