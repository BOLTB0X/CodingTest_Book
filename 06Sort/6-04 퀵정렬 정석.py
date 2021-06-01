#6-4 퀵정렬 정석
arr=[5,7,9,0,3,1,6,2,4,8]
def quick_sort(arr,start,end):
    if start >= end: #원소가 1개일 경우 대비
        return
    pviot = start #피벗을 리스트의 첫번째 원소로 셋팅
    left=start+1 #피벗보다 한 칸 앞으로
    right=end #맨끝으로 셋팅
    while left <= right: #left가 right가 작으므로 한칸씩 증가시면서 반복문 시작
        #피벗보다 큰 값을 찾도록 탐색 시작
        while left<=end and arr[left] <= arr[pviot]: #피벗이 왼쪽 보다 작아야하므로 반복문 조건을 반대로
            left+=1
        while right>start and arr[right]>= arr[pviot]: #피벗이 오른쪽 보다 커야하므로 반복문 조건을 반대로
            right-=1
        if left > right: #엇갈린 경우
            arr[right],arr[pviot]=arr[pviot],arr[right] #오른쪽과 피벗을 스와프
        else: #그 외인 경우
            arr[left],arr[right]=arr[right],arr[left] #왼쪽 오른쪽 스와프
    #분할 이후 왼쪽 오른쪽 부분에서 각자 정렬 수행
    quick_sort(arr,start,right-1)
    quick_sort(arr,right+1,end)
quick_sort(arr,0,len(arr)-1)
print(arr) #오름차순 정렬