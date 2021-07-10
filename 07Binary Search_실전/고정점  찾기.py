n=int(input())
nums=list(map(int,input().split()))

#이진 탐색
def Binary_search(nums,start,end):
    #존재하지 않는 경우
    if start > end:
        return None

    mid = (start + end)//2
    if nums[start] == mid: #찾은 경우
        return mid

    elif nums[mid] > mid:
        return Binary_search(nums,start,mid-1)
    else:
        return Binary_search(nums,mid+1,end)

idx=Binary_search(nums,0,n-1)
print(idx if idx>=0 else -1)