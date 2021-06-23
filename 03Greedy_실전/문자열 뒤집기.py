nums=input()
zero_cnt=0
one_cnt=0
if nums[0]=='1':
    zero_cnt+=1
else:
    one_cnt+=1
for i in range(len(nums)-1):
    if nums[i] != nums[i+1]:
        if nums[i+1]=='1':
            zero_cnt+=1
        else:
            one_cnt+=1
print(min(zero_cnt,one_cnt))