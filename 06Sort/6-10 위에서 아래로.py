#위에서 아래로
n=int(input())
nums=[]
for i in range(n):
    nums.append(int(input()))
nums=sorted(nums,reverse=True)
print(*nums)