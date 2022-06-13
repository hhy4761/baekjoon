n = int(input())
for i in range(n):
    num = int(input())
    fibo = []
    for j in range(num+1):
        if j==0:
            fibo.append(0)
        elif j==1:
            fibo.append(1)
        else:
            fibo.append(fibo[j-2]+fibo[j-1])
    if num == 0:
        print("1 0")
    else:
        print(f'{fibo[num-1]} {fibo[num]}')