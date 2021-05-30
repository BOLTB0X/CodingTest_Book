#3-3 숫자카드 게임 풀이1
n,m=map(int,input().split())
result=0
for i in range(n):
    cards=list(map(int,input().split()))
    min_value=min(cards)
    result=max(result,min_value)
print(result)

#3-3 숫자카드 게임풀이2
n,m=map(int,input().split())
ans=0
for i in range(n):
    cards=list(map(int,input().split()))
    min_value=10001
    for a in cards:
        min_value=min(min_value,a)
    #최솟값들 중에서 최댓값 찾기
    ans=max(ans,min_value)
print(ans)