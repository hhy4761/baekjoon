import sys
input = sys.stdin.readline

n,m = map(int,input().split())
not_listend = set()
not_looked = set()
for i in range(n):
    not_listend.add(input().rstrip())
for j in range(m):
    not_looked.add(input().rstrip())

inter = not_listend & not_looked
ans = sorted(list(inter))
print(len(ans))
for a in ans:
    print(a)