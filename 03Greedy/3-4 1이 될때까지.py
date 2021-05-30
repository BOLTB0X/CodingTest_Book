#3-4-1 1이 될때가지 내 풀이
n,k=map(int,input().split())
cnt=0
while True:
    if n==1:
        break
    if n%k==0:
        n//=k
        cnt+=1
    else:
        n-=1
        cnt+=1
print(cnt)

#3-4-2 1이 될때까지 단순 풀이
n,k=map(int,input().split())
ans=0

while n>=k:
    while n%k !=0:
        n-=1
        ans+=1
    n//=k
    ans+=1
while n>1:
    n-=1
    ans+=1
print(ans)

#3-4-3 1이 될때까지 정석풀이
n,k=map(int,input().split())
result=0;

while True:
    target=(n//k)*k #n을 나누어 떨어지게 만들기
    result+=(n-target) #이 차이가 횟수
    n=target
    #더 이상 나눌수 없을 때
    if n<k:
        break
  #k로 나누기
    result +=1
    n//=k

# 마지막으로 남은 수에 대하여 1씩 뺴기
result += (n-1)
print(result)