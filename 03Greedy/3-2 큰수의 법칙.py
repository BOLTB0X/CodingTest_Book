#3-2-1 큰 수의 법칙
n,m,k=map(int,input().split())
nums=list(map(int,input().split()))
nums.sort(reverse=True)
fir=nums[0]
sec=nums[1]
result=0
while True:
    for i in range(k):
        if m==0:
            break
        result+=fir
        m-=1
    if m==0:
        break;
    result+=sec
    m-=1
print(result)

#3-2-2 큰 수의 법칙 다른 풀이
n,m,k=map(int,input().split())
nums=list(map(int,input().split()))
nums.sort()
fir=nums[n-1]
sec=nums[n-2]
cnt=int(m/(k+1))*k
cnt+=m%(k+1)
result=0
result+=cnt*fir
result+=(m-cnt)*sec
print(result)