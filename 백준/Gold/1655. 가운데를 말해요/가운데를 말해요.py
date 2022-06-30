import sys
import heapq

input=sys.stdin.readline
n = int(input().rstrip())
min_heap = []
max_heap = []
for i in range(n):
    num = int(input().rstrip())
    if len(max_heap) == 0:
        heapq.heappush(max_heap,-num)
        print(-max_heap[0])
        continue
    if -max_heap[0] < num:
        heapq.heappush(min_heap,num)
    else:
        heapq.heappush(max_heap,-num)
    if len(min_heap) > len(max_heap):
        heapq.heappush(max_heap,-heapq.heappop(min_heap))
    elif len(min_heap) < len(max_heap):
        while abs(len(min_heap)-len(max_heap)) > 1:
            heapq.heappush(min_heap,-heapq.heappop(max_heap))
    print(-max_heap[0])
        