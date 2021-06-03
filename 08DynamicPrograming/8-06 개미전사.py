#실전3 개미전사
n=int(input())
b=list(map(int,input().split()))
#dp 초기화
d=[0]*100
#DP 진행(보텀업)
d[0]=b[0]
d[1]=max(b[0],b[1])
for i in range(2,n):
    d[i]=max(d[i-1],d[i-2]+b[i])
print(d[n-1])