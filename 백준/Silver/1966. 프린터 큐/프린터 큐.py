import sys
from collections import deque
input = sys.stdin.readline
t = int(input().rstrip())
for _ in range(t):
    n,m = map(int,input().split())
    priority = deque(list(map(int,input().split())))
    for i in range(len(priority)):
        priority[i] = (priority[i],i)
    cnt = 0
    while priority:
        
        cur_max = max(priority, key=lambda x: x[0])
        if priority[0][0] < cur_max[0]:
            priority.append(priority.popleft())
        else:
            cur_pop = priority.popleft()
            cnt += 1
        
            if cur_pop[1] == m:
                break
        
    print(cnt)
    

