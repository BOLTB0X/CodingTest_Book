#이진 탐색 소스코드 구현(while)
def binary_search(arr,target,start,end):
    while start <= end:
        mid=(start+end)//2
        #찾은 경우 중간점 인덱스 반환
        if arr[mid]==target:
            return mid
        #중간점 인덱스의 값보다 target이 작은 경우
        if arr[mid]>target:
            end=mid-1 #왼쪽 확인
        #중간점 인덱스의 값보다 target이 큰 경우
        else:
            start=mid+1 #오른쪽 확인
    return None
n,target=map(int,input().split())
arr=list(map(int,input().split()))
result=binary_search(arr,target,0,n-1)
if result==None:
    print('원소존재X')
else:
    print(result+1)