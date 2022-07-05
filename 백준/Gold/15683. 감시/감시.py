import sys
from collections import deque
import copy
import time
# def dfs(graph,cctv_idx,total):
    

input = sys.stdin.readline
n,m = map(int,input().split())
graph = [[0]*m for _ in range(n)]
cctv_idx = []
for i in range(n):
    graph[i] = list(map(int,input().split()))

for i in range(n):
    for j in range(m):
        if graph[i][j] != 0 and graph[i][j] != 6:
            cctv_idx.append((i,j,graph[i][j]))
# print(cctv_idx)
if cctv_idx:
    stack = list()
    ans = []
    cnt = 0
    x,y,cctv = cctv_idx[cnt]

    # last element = {0:right,1:down,2:left,3:up}
    if cctv == 1 or cctv == 3 or cctv == 4:
        for i in range(4):
            copy_graph = copy.deepcopy(graph)
            stack.append((x,y,cctv,i,copy_graph,cnt))
    elif cctv == 2:
        for i in range(2):
            copy_graph = copy.deepcopy(graph)
            stack.append((x,y,cctv,i,copy_graph,cnt))
    elif cctv == 5:
        copy_graph = copy.deepcopy(graph)
        stack.append((x,y,cctv,0,copy_graph,cnt))
    while stack:
        x,y,cctv,dir,copy_graph,cnt = stack.pop()
        right_x = x
        left_x = x
        right_y = y
        left_y = y
        if cctv == 1:
            if dir == 0:
                while y < m-1:
                    y += 1
                    if copy_graph[x][y] == 0:  
                        copy_graph[x][y] = -1
                    elif copy_graph[x][y] == 6:
                        break
            elif dir == 1:
                while x < n-1:
                    x += 1
                    if copy_graph[x][y] == 0:  
                        copy_graph[x][y] = -1
                    elif copy_graph[x][y] == 6:
                        break
            elif dir == 2:
                while y > 0:
                    y -= 1
                    if copy_graph[x][y] == 0:  
                        copy_graph[x][y] = -1
                    elif copy_graph[x][y] == 6:
                        break
            elif dir == 3:
                while x > 0:
                    x -= 1
                    if copy_graph[x][y] == 0:  
                        copy_graph[x][y] = -1
                    elif copy_graph[x][y] == 6:
                        break
        elif cctv == 2:
            if dir == 0 or dir == 2:
                while right_y < m-1:
                    right_y += 1
                    if copy_graph[x][right_y] == 0:  
                        copy_graph[x][right_y] = -1
                    elif copy_graph[x][right_y] == 6:
                        break
                while left_y > 0:
                    left_y -= 1
                    if copy_graph[x][left_y] == 0:  
                        copy_graph[x][left_y] = -1
                    elif copy_graph[x][left_y] == 6:
                        break
            elif dir == 1 or dir == 3:
                while right_x < n-1:
                    right_x += 1
                    if copy_graph[right_x][y] == 0:  
                        copy_graph[right_x][y] = -1
                    elif copy_graph[right_x][y] == 6:
                        break
                while left_x > 0:
                    left_x -= 1
                    if copy_graph[left_x][y] == 0:  
                        copy_graph[left_x][y] = -1
                    elif copy_graph[left_x][y] == 6:
                        break
        elif cctv == 3:
            if dir == 0:
                while right_y < m-1:
                    right_y += 1
                    if copy_graph[x][right_y] == 0:  
                        copy_graph[x][right_y] = -1
                    elif copy_graph[x][right_y] == 6:
                        break
                while left_x > 0:
                    left_x -= 1
                    if copy_graph[left_x][y] == 0:  
                        copy_graph[left_x][y] = -1
                    elif copy_graph[left_x][y] == 6:
                        break
            elif dir == 1:
                while right_y < m-1:
                    right_y += 1
                    if copy_graph[x][right_y] == 0:  
                        copy_graph[x][right_y] = -1
                    elif copy_graph[x][right_y] == 6:
                        break
                while right_x < n-1:
                    right_x += 1
                    if copy_graph[right_x][y] == 0:  
                        copy_graph[right_x][y] = -1
                    elif copy_graph[right_x][y] == 6:
                        break
            elif dir == 2:
                while left_y > 0:
                    left_y -= 1
                    if copy_graph[x][left_y] == 0:  
                        copy_graph[x][left_y] = -1
                    elif copy_graph[x][left_y] == 6:
                        break
                while right_x < n-1:
                    right_x += 1
                    if copy_graph[right_x][y] == 0:  
                        copy_graph[right_x][y] = -1
                    elif copy_graph[right_x][y] == 6:
                        break
            elif dir == 3:
                while left_y > 0:
                    left_y -= 1
                    if copy_graph[x][left_y] == 0:  
                        copy_graph[x][left_y] = -1
                    elif copy_graph[x][left_y] == 6:
                        break
                while left_x > 0:
                    left_x -= 1
                    if copy_graph[left_x][y] == 0:  
                        copy_graph[left_x][y] = -1
                    elif copy_graph[left_x][y] == 6:
                        break
        elif cctv == 4:
            if dir == 0:
                while right_y < m-1:
                    right_y += 1
                    if copy_graph[x][right_y] == 0:  
                        copy_graph[x][right_y] = -1
                    elif copy_graph[x][right_y] == 6:
                        break
                while right_x < n-1:
                    right_x += 1
                    if copy_graph[right_x][y] == 0:  
                        copy_graph[right_x][y] = -1
                    elif copy_graph[right_x][y] == 6:
                        break
                while left_x > 0:
                    left_x -= 1
                    if copy_graph[left_x][y] == 0:  
                        copy_graph[left_x][y] = -1
                    elif copy_graph[left_x][y] == 6:
                        break
            elif dir == 1:
                while right_y < m-1:
                    right_y += 1
                    if copy_graph[x][right_y] == 0:  
                        copy_graph[x][right_y] = -1
                    elif copy_graph[x][right_y] == 6:
                        break
                while right_x < n-1:
                    right_x += 1
                    if copy_graph[right_x][y] == 0:  
                        copy_graph[right_x][y] = -1
                    elif copy_graph[right_x][y] == 6:
                        break
                while left_y > 0:
                    left_y -= 1
                    if copy_graph[x][left_y] == 0:  
                        copy_graph[x][left_y] = -1
                    elif copy_graph[x][left_y] == 6:
                        break
            elif dir == 2:
                while left_y > 0:
                    left_y -= 1
                    if copy_graph[x][left_y] == 0:  
                        copy_graph[x][left_y] = -1
                    elif copy_graph[x][left_y] == 6:
                        break
                while right_x < n-1:
                    right_x += 1
                    if copy_graph[right_x][y] == 0:  
                        copy_graph[right_x][y] = -1
                    elif copy_graph[right_x][y] == 6:
                        break
                while left_x > 0:
                    left_x -= 1
                    if copy_graph[left_x][y] == 0:  
                        copy_graph[left_x][y] = -1
                    elif copy_graph[left_x][y] == 6:
                        break
            elif dir == 3:
                while right_y < m-1:
                    right_y += 1
                    if copy_graph[x][right_y] == 0:  
                        copy_graph[x][right_y] = -1
                    elif copy_graph[x][right_y] == 6:
                        break
                while left_y > 0:
                    left_y -= 1
                    if copy_graph[x][left_y] == 0:  
                        copy_graph[x][left_y] = -1
                    elif copy_graph[x][left_y] == 6:
                        break
                while left_x > 0:
                    left_x -= 1
                    if copy_graph[left_x][y] == 0:  
                        copy_graph[left_x][y] = -1
                    elif copy_graph[left_x][y] == 6:
                        break
        elif cctv == 5:
            while right_y < m-1:
                right_y += 1
                if copy_graph[x][right_y] == 0:  
                    copy_graph[x][right_y] = -1
                elif copy_graph[x][right_y] == 6:
                    break
            while left_y > 0:
                left_y -= 1
                if copy_graph[x][left_y] == 0:  
                    copy_graph[x][left_y] = -1
                elif copy_graph[x][left_y] == 6:
                    break
            while left_x > 0:
                left_x -= 1
                if copy_graph[left_x][y] == 0:  
                    copy_graph[left_x][y] = -1
                elif copy_graph[left_x][y] == 6:
                    break
            while right_x < n-1:
                right_x += 1
                if copy_graph[right_x][y] == 0:  
                    copy_graph[right_x][y] = -1
                elif copy_graph[right_x][y] == 6:
                    break
        cnt += 1
        if cnt != len(cctv_idx):
            x,y,cctv = cctv_idx[cnt]
            if cctv == 1 or cctv == 3 or cctv == 4:
                for i in range(4):
                    updated_graph = copy.deepcopy(copy_graph)
                    stack.append((x,y,cctv,i,updated_graph,cnt))
            elif cctv == 2:
                for i in range(2):
                    updated_graph = copy.deepcopy(copy_graph)
                    stack.append((x,y,cctv,i,updated_graph,cnt))
            elif cctv == 5:
                updated_graph = copy.deepcopy(copy_graph)
                stack.append((x,y,cctv,i,updated_graph,cnt))
        
        else:
            num = 0
            for i in range(n):
                for j in range(m):
                    if copy_graph[i][j] == 0:
                        num += 1
            ans.append(num)

    print(min(ans))
    # print(dfs(graph,cctv_idx,len(cctv_idx)))
else:
    count = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                count += 1
    print(count)