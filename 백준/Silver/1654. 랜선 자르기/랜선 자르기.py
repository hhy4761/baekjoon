import sys

input = sys.stdin.readline
k,n = map(int,input().split())
wires = []
for _ in range(k):
    wires.append(int(input().rstrip()))
wires.sort()
start,end = 1,max(wires)

while start <= end:
    mid = (end+start)//2
    total = 0

    for wire in wires:
        total += wire//mid

    if total >= n:
        start = mid+1
    else:
        end = mid-1
print(end)