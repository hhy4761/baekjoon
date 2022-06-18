import sys
input = sys.stdin.readline

arr = []
n = int(input())
for i in range(n):
    s,e = map(int,input().split())
    arr.append((s,e))

arr.sort(key=lambda x: (x[1],x[0]))

last_time = 0
count = 0
for s,e in arr:
    if s >= last_time:
        last_time = e
        count +=1

print(count)