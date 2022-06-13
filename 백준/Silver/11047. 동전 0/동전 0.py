num, value = map(int,input().split())
coins = []
for i in range(num):
    coins.append(int(input()))

count = 0
while value != 0:
    for i in reversed(range(len(coins))):
        if coins[i] <= value:
            iter = value // coins[i]
            value -= coins[i]*iter
            count += iter
            break
print(count)