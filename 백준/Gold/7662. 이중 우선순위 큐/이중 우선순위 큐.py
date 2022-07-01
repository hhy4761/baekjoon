import sys
import heapq
from collections import defaultdict

input=sys.stdin.readline
t = int(input().rstrip())
for i in range(t):
    min_heap = []
    max_heap = []
    m = defaultdict(int)
    n = int(input().rstrip())
    length = 0
    for j in range(n):
        s,num = input().split()
        num = int(num)
        if s=='I':
            length += 1
            heapq.heappush(min_heap,num)
            heapq.heappush(max_heap,-num)
            m[num] += 1
        else: #s=='D'
            if length > 0:
                if num == 1:
                    while m[-max_heap[0]] == 0: 
                        heapq.heappop(max_heap)
                    if max_heap:
                        m[-heapq.heappop(max_heap)]-=1
                else: #-1
                    while m[min_heap[0]] == 0: 
                        heapq.heappop(min_heap)
                    if min_heap:
                        m[heapq.heappop(min_heap)]-=1
                length -= 1

    if length > 0 :
        while m[-max_heap[0]] == 0: 
            heapq.heappop(max_heap)
        while m[min_heap[0]] == 0: 
            heapq.heappop(min_heap)
        print(-max_heap[0],min_heap[0])
    else:
        print("EMPTY")