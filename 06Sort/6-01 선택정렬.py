arr=[7,5,9,0,3,1,6,2,4,8]
for i in range(len(arr)):
    idx=i
    for j in range(i+1,len(arr)):
        if arr[idx]>arr[j]: #idx가 j보다 크다면
            idx=j #j로 변경
    arr[i],arr[idx]=arr[idx],arr[i] #스와프
print(arr) #오름차순 정렬

arr=[7,5,9,0,3,1,6,2,4,8]
for i in range(len(arr)):
    idx=i
    for j in range(i+1,len(arr)):
        if arr[idx]<arr[j]:
            idx=j
    arr[i],arr[idx]=arr[idx],arr[i] #스와프
print(arr) #내림차순 정렬
