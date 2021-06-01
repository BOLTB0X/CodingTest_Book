#순차
n=int(input())
n_list=list(map(int,input().split()))
m=int(input())
m_list=list(map(int,input().split()))
for i in m_list:
    if i in n_list:
        print('yes',end=' ')
    else:
        print('no',end=' ')

#반복
def binary_search(n_arr,target,start,end):
    while start<=end:
        mid=(start+end)//2
        if n_arr[mid]==target:
            return mid
        elif n_arr[mid]>target:
            end= mid-1
        else:
            start=mid+1
    return None
n=int(input())
n_arr=list(map(int,input().split()))
n_arr.sort()
m=int(input())
m_arr=list(map(int,input().split()))
#손님의 요청 하나씩 확인
for x in m_arr:
    result=binary_search(n_arr,x,0,n-1)
    if result!=None:
        print('yes',end=' ')
    else:
        print('no',end=' ')