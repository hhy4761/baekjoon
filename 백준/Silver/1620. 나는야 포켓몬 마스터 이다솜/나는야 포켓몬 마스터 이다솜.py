import sys
input = sys.stdin.readline

N,M = map(int,input().split())
info_num_to_name = {}
info_name_to_num = {}

# Complete dict
for i in range(N):
    name = input().rstrip()
    info_num_to_name[i+1] = name
    info_name_to_num[name] = i+1

# Searching
for _ in range(M):
    inputs = input().rstrip()
    if inputs.isdigit():
        print(info_num_to_name.get(int(inputs)))
    else:
        print(info_name_to_num.get(inputs))