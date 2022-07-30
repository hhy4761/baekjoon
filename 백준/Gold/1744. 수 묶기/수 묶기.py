import sys
input = sys.stdin.readline
n = int(input().rstrip())
positive_nums = []
negative_nums = []
for _ in range(n):
    num = int(input().rstrip()) 
    if num > 0:
        positive_nums.append(num)
    else:
        negative_nums.append(num)
positive_nums = sorted(positive_nums,reverse=True)
negative_nums = sorted(negative_nums)

i = 0
res = []
while True:
    if i >= len(positive_nums) :
        break
    if i < len(positive_nums)-1 and (positive_nums[i]+positive_nums[i+1] < positive_nums[i]*positive_nums[i+1]):
        res.append(positive_nums[i]*positive_nums[i+1])
        i+=2
    else:
        res.append(positive_nums[i])
        i+=1
i = 0
while True:
    if i >= len(negative_nums) :
        break
    if i < len(negative_nums)-1 and (negative_nums[i]+negative_nums[i+1] < negative_nums[i]*negative_nums[i+1]):
        res.append(negative_nums[i]*negative_nums[i+1])
        i+=2
    else:
        res.append(negative_nums[i])
        i+=1
print(sum(res))