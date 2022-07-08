import sys
input = sys.stdin.readline
n = int(input().rstrip())

arr = []

for _ in range(n):
    arr.append(int(input().rstrip()))

ans = [[0] for _ in range(n)]

if len(arr) > 2:
    ans[0] = arr[0]
    ans[1] = arr[0]+arr[1]
    ans[2] = max(arr[0]+arr[2],arr[1]+arr[2])

    for i in range(3,n):
        ans[i] = max(ans[i-2],ans[i-3]+arr[i-1]) + arr[i]
    print(ans[n-1])

else:
    if len(arr) == 1:
        print(arr[0])
    else:
        print(arr[0]+arr[1])
