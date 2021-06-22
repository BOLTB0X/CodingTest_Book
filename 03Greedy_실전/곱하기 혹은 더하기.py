nums=input()
answer=int(nums[0])
for i in range(1,len(nums)):
    num=int(nums[i])
    if answer<=1 or num <=1:
        answer+=int(num)
    else:
        answer*=int(num)
print(answer)
        