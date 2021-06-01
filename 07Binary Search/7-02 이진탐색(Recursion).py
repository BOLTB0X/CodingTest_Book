#이진 탐색 소스코드 구현(재귀)
def binary_search(arr,target,start,end):
    if start > end:
        return None
    mid = (start+end)//2 #mid 정의
    #mid 인덱스에 타겟이 있는 경우
    if arr[mid]==target:
        return mid
    #mid 인덱스의 값보다 찾고자 하는 값이 작은 경우
    elif arr[mid]>target:
        return binary_search(arr,target,start,mid-1) #왼쪽 확인
    #mid 인덱스의 값보다 찾고자 하는 값이 큰 경우
    else:
        return binary_search(arr, target, mid+1, end)  # 오른쪽 확인
n,target=map(int,input().split())
arr=list(map(int,input().split()))
result=binary_search(arr,target,0,n-1)
if result==None:
    print('원소존재X')
else:
    print(result+1)