import sys
import heapq
input = sys.stdin.readline
n = int(input().rstrip())
stack = list(map(int,input().split()))
top = [0] * len(stack)
heap = []
for i in (range(len(stack)-1,-1,-1)):
    num = stack.pop()
    heapq.heappush(heap,(num,i))
    while num > heap[0][0]:
        n, index = heapq.heappop(heap)
        top[index] = i+1
for ele in top:
    print(ele,end=" ")