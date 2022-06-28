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
            if a[1] == 0:
                print(-a[0])
            else:
                print(a[0])
            
        elif val > 0:
            heapq.heappush(heap,(abs(val),1))
        elif val < 0:
            heapq.heappush(heap,(abs(val),0))
    else:
        if val == 0:
            print(0)
        elif val > 0:
            heapq.heappush(heap,(abs(val),1))
        elif val < 0:
            heapq.heappush(heap,(abs(val),0))