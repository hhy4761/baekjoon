import sys

input = sys.stdin.readline
n,c = map(int,input().split())
houses = []
for _ in range(n):
    houses.append(int(input().rstrip()))
houses.sort()
start,end = 0,max(houses)

while start <= end:
    mid = (end+start)//2
    total = 1
    cur = houses[0]
    for i in range(1,len(houses)):
        if houses[i]-cur >= mid:
            total += 1
            cur = houses[i]

    if total >= c:
        start = mid+1
    else:
        end = mid-1
print(end)