n,m=map(int,input().split()) #떡의 개수:N, 떡의 길이:M
heights=list(map(int,input().split())) #떡의 높이들
start=0
end=max(heights)
result=0
#반복 시작
while start <= end:
    tot=0
    mid=(start+end)//2
    for x in heights:
        #잘랐을때 잘린 떡의 값을 넣음
        if x> mid:
            tot+=x-mid
    if tot<m: #고객 요청보다 모자르면
        end = mid-1 #왼쪽 탐색시작
    else:
        result=mid
        start=mid+1
print(result)
