#6-3 삽입정렬
arr=[7,5,9,0,3,1,6,2,4,8]
for i in range(1,len(arr)): #첫 번째보다 한칸 앞으로 반복문 설정
    for j in range(i,0,-1): # 그 i부터 반대로 반복문 설정
        if arr[j-1]>arr[j]: #앞에 있는 넘이 더 크다면
            arr[j-1],arr[j]=arr[j],arr[j-1] #스와프
print(arr) #오름차순

arr=[7,5,9,0,3,1,6,2,4,8]
for i in range(1,len(arr)):
    for j in range(i,0,-1):
        if arr[j-1]<arr[j]: #앞에 있는 넘이 작으면
            arr[j-1],arr[j]=arr[j],arr[j-1]
print(arr) #내림차순