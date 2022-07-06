import sys
import copy

input = sys.stdin.readline
n,m,k = map(int,input().split())
grid = [[0]*m for _ in range(n)]
stickers = []

for i in range(k):
    row,col = map(int,input().split())
    sticker = [[0] * col for _ in range(row)]
    for j in range(row):
        sticker[j] = list(map(int,input().split()))
    stickers.append(sticker)


def check_position(grid,sticker):
    s = copy.deepcopy(sticker)
    for _ in range(4):
        # print(s)
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if (len(grid)-i-len(s) >= 0 and len(grid[i])-j-len(s[0])>=0):
                    is_pass = True
                    for x in range(len(s)):
                        for y in range(len(s[x])):
                            if s[x][y] == 1 and grid[i+x][j+y] == 1:
                                is_pass = False
                                break
                        if not is_pass:
                            break
                    if is_pass:
                        return (i,j,s)
        s = rotate(s)
    return -1

def rotate(sticker):
    ret = [[0]*len(sticker) for _ in range(len(sticker[0]))]
    for i in range(len(ret)):
        for j in range(len(ret[i])):
            ret[i][j] = sticker[len(ret[0])-1-j][i]
    return ret

for sticker in stickers:
    pos = check_position(grid,sticker)
    if pos != -1:
        x,y,s = pos
        for i in range(len(s)):
            for j in range(len(s[0])):
                if s[i][j] == 1:
                    grid[x+i][y+j] = s[i][j]
count=0
for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] == 0:
            count += 1
print(n*m - count)