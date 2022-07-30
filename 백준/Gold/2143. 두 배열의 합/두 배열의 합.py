import sys,bisect
input = sys.stdin.readline

t = int(input().rstrip())
n = int(input().rstrip())
a = list(map(int,input().split()))
m = int(input().rstrip())
b = list(map(int,input().split()))

def get_partial_sum(leng,arr):
    result = []
    for i in range(leng):
        for j in range(i+1,leng+1):
            result.append(sum(arr[i:j]))
    return sorted(result)

a_sum = get_partial_sum(n,a)
b_sum = get_partial_sum(m,b)

ans = 0

for s in a_sum:
    l = bisect.bisect_left(b_sum,t-s)
    r = bisect.bisect_right(b_sum,t-s)
    ans += (r-l)
print(ans)