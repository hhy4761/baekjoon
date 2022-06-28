import sys
import heapq

input=sys.stdin.readline
n = int(input().rstrip())
heap = []
for _ in range(n): 
    val = int(input().rstrip())
    if heap:
        if val == 0:
            a = heapq.heappop(heap)
            print(a)
        else:
            heapq.heappush(heap,val)
    else:
        if val == 0:
            print(0)
        else:
            heapq.heappush(heap,val)