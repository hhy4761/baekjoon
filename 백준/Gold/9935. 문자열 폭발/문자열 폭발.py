import sys
input = sys.stdin.readline

s = input().rstrip()
s2 = input().rstrip()
length = len(s2)
arr = []
for i in s:
    arr.append(i)
    if ''.join(arr[-length:]) == s2:
        del arr[-length:]
if arr:           
    print(''.join(arr))
else:
    print("FRULA")