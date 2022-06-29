import sys
import heapq
from collections import deque

input=sys.stdin.readline
n = int(input().rstrip())

last_time = 0
last_count = 0
count = 0
heap = list()
heap2 = list()
for i in range(n):
    s,e = map(int,input().split())
    heapq.heappush(heap,(s,e))

# insert 1st class into heap2
s,e = heapq.heappop(heap)
heapq.heappush(heap2,(e))

while heap:
    last_time = heap2[0]
    s,e = heapq.heappop(heap)
    if last_time > s:
        heapq.heappush(heap2,(e))
    else:
        heapq.heappop(heap2)
        heapq.heappush(heap2,(e))

    
print(len(heap2))