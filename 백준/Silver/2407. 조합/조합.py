import sys

input = sys.stdin.readline
n,m = map(int,input().split())

sum = 1
for i in range(m):
    sum *= (n-i)
for i in range(m):
    sum //= m-i
print((sum))