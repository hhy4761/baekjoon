import sys
input = sys.stdin.readline

stack = []
n = int(input().rstrip())
for _ in range(n):
    ops = list(map(str,input().split()))
    if len(ops) > 1:
        stack.append(ops[1])
    else:
        if ops[0] == 'top':
            if stack:
                print(stack[-1])
            else:
                print(-1)
        elif ops[0] == 'size':
            print(len(stack))
        elif ops[0] == 'empty':
            if stack:
                print(0)
            else:
                print(1)
        elif ops[0] == 'pop':
            if stack:
                print(stack.pop())
            else:
                print(-1)