import sys
import heapq

input=sys.stdin.readline
n = int(input().rstrip())
heap=[]
for i in range(n):
    heap.append(int(input().rstrip()))

heapq.heapify(heap)
sum = 0
ans =0 
count = 0
while heap:
    if len(heap) >= 2:
        a = heapq.heappop(heap)
        b = heapq.heappop(heap)
        sum = a+b
    elif len(heap) == 1:
        heapq.heappop(heap)
        sum = 0
    elif len(heap) == 0:
        sum = 0
    if heap:
        heapq.heappush(heap,sum)
    ans += sum

print(ans)