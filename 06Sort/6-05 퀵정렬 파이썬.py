#6-5 퀵정렬
arr=[5,7,9,0,3,1,6,2,4,8]
def quick_sort(arr):
    if len(arr)<=1: #리스트 길이가 1인 경우 대비
        return arr

    pivot = arr[0] #피벗 첫번째 원소로 셋팅
    tail = arr[1:] #피벗을 제외한 리스트

    left_side=[x for x in tail if x<=pivot] #분할된 왼쪽 ==> 피벗값보다 작은 원소들로만 리스트 생성
    right_side=[x for x in tail if x>pivot] #분할된 오른쪽 ==> 피벗값보다 큰 원소들로만 리스트 생성

    return quick_sort(left_side)+[pivot]+quick_sort(right_side)
print(quick_sort(arr)) #오름차순

arr=[5,7,9,0,3,1,6,2,4,8]
def quick_sort(arr):
    if len(arr)<=1: #리스트 길이가 1인 경우 대비
        return arr

    pivot = arr[0] #피벗 첫번째 원소로 셋팅
    tail = arr[1:] #피벗을 제외한 리스트

    left_side=[x for x in tail if x<=pivot] #분할된 왼쪽 ==> 피벗값보다 작은 원소들로만 리스트 생성
    right_side=[x for x in tail if x>pivot] #분할된 오른쪽 ==> 피벗값보다 큰 원소들로만 리스트 생성

    return quick_sort(right_side)+[pivot]+quick_sort(left_side)
print(quick_sort(arr)) #내름차순