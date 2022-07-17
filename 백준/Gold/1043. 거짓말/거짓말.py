import sys
input = sys.stdin.readline
n,m = map(int,input().split())
true_list = set(map(int,input().split()[1:]))
party = [set(map(int,input().split()[1:])) for _ in range(m)]

for _ in range(m):
    for p in party:
        if true_list & p:
            true_list |= p

cnt = m
for p in party:
    if true_list & p:
        cnt -= 1
print(cnt)