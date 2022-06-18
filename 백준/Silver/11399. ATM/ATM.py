import sys
input = sys.stdin.readline

n = int(input().rstrip())
time = input().rstrip()
time = sorted(map(int,time.split()))

for i in range(len(time)):
    if i ==0:
        continue
    time[i] += time[i-1]
print(sum(time))