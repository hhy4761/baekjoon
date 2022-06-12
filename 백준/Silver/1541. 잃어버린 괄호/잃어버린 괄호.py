import re

input = input()
nums = re.split("[+-]", input)
mark = list(re.sub(r'[^+-]', "", input))
p = re.compile('^0')

for i in range(len(nums)):
    if p.match(nums[i]):
        nums[i] = re.sub(r'^0*',"",nums[i])
        if nums[i] == '':
            nums[i] = '0'

new_form = []
index = 0
while True:
    if len(nums) == len(mark):
        new_form.append(mark[index])
        new_form.append(nums[index])
        if index == len(nums)-1:
            new_form.remove('')
            break
    else:
        new_form.append(nums[index])
        if index == len(nums)-1:
            break
        new_form.append(mark[index])
    index += 1

exp = []

start = False
for i in range(len(new_form)):
    exp.append(new_form[i])
    if not start and new_form[i] == '-':
        exp.append('(')
        start = True
    elif start and new_form[i] == '-':
        exp.insert(-1, ')')
        exp.append('(')
    elif start and i == len(new_form)-1:
        exp.append(')')
        start = False
exp = ''.join(exp)
print(eval(exp))
