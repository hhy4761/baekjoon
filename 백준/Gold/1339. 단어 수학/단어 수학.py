import sys
import heapq
import copy
from collections import defaultdict,Counter

input = sys.stdin.readline
n = int(input().rstrip())
words = []
num = defaultdict(int)

for i in range(n):
    word = input().rstrip()
    words.append(word)
    for x in range(len(word)):
        num[word[x]] += 10**(len(word)-1-x)

heap = []
for k,v in num.items():
    heapq.heappush(heap,(-v,k))

result = 0
count = 9
while heap:
    v,k = heapq.heappop(heap)
    v = -v*count
    result += v
    count -= 1
print(result)
