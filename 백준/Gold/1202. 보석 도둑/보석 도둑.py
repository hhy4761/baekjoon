import sys
import heapq

input = sys.stdin.readline
n,k = map(int,input().split())
jewelry = []
bag = []

for _ in range(n):
    m,v = map(int,input().split())
    heapq.heappush(jewelry,(m,v))
for _ in range(k):
    w = int(input().rstrip())
    heapq.heappush(bag,w)
    
sum = 0
temp = []

while bag:
    w = heapq.heappop(bag)
    while jewelry and jewelry[0][0] <= w:
        m,v = heapq.heappop(jewelry)
        heapq.heappush(temp,-v)
    if temp:
        sum += -heapq.heappop(temp)
print(sum)