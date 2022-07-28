import sys
input = sys.stdin.readline

n = int(input().rstrip())
p = int(input().rstrip())

def find(target):
    if target == parent[target]:
        return target
    parent[target] = find(parent[target])
    return parent[target]

parent = [i for i in range(n+1)]
planes = []
for _ in range(p):
    planes.append(int(input().rstrip()))

answer = 0 
for p in planes:
    docking = find(p)
    if docking == 0:
        break
    parent[docking] = parent[docking-1]
    answer += 1
print(answer)