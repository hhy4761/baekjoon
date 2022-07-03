import sys
import heapq
from collections import deque
input = sys.stdin.readline
n = int(input().rstrip())
queue = deque(map(int,input().split()))
top = [-1] * len(queue)
heap = []
for i in range(len(queue)):
    num = queue.popleft()
    heapq.heappush(heap,(num,i))
    while num > heap[0][0]:
        n, index = heapq.heappop(heap)
        top[index] = num
for ele in top:
    print(ele,end=" ")