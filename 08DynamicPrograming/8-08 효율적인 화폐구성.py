#실전5 효율적인 화폐구성
n,m=map(int,input().split())
arr=[]
for i in range(n):
    arr.append(int(input()))
#DP테이블 초기화
d=[10001]*(m+1)
#보텀업
d[0]=0
for i in range(n):
    for j in range(arr[i],m+1):
        if d[j-arr[i]]!=10001: #(1-k)원을 만드는 방법이 존재
            d[j]=min(d[j],d[j-arr[i]]+1)
#계산된 결과 출력
if d[m] == 10001: #최종적으로 m원을 만드는 방법이 없는 경우
    print(-1)
else:
    print(d[m])