from collections import deque
import sys
input = sys.stdin.readline

def bfs(f,t):
    queue = deque()
    visited = set()
    queue.append((f,''))

    while queue:
        x,y = queue.popleft()
        if x == t:
            print(y)
            return
        
        if x != 0:
            #D
            res = 2*x
            if res > 9999:
                res = res % 10000
            if res not in visited:
                visited.add(res)
                queue.append((res,y+'D'))
            #L
            # res = list(str(x))
            # while len(res) != 4:
            #     res.insert(0,'0')
            # res = int(res[1] + res[2] + res[3] + res[0])
            res = (( x % 1000) * 10) + (x // 1000)
            if res not in visited:
                visited.add(res)
                queue.append((res,y + 'L'))
            #R
            # res = list(str(x))
            # while len(res) != 4:
            #     res.insert(0,'0')
            # res = int(res[3] + res[0] + res[1] + res[2])
            res = ((x % 10) * 1000) + (x//10)
            if res not in visited:
                visited.add(res)
                queue.append((res,y + 'R'))
        #S
        res = x-1
        if res == -1:
            res = 9999
        if res not in visited:
            visited.add(res)
            queue.append((res,y + 'S'))  
            

N = int(input().rstrip())
for _ in range(N):
    f,t = map(int,input().split())
    bfs(f,t)