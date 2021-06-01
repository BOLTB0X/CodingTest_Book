#6-6 계수정렬
#모든 원소의 값이 0보다 크거나 같다고 가정
array=[7,5,9,0,3,1,6,2,9,1,4,8,0,5,2]
#모든 범위를 포함하는 리스트선언(모든 값은 0으로 초기화)
cnt=[0]*(max(array)+1)

for i in range(len(array)):
    cnt[array[i]]+=1 #카운트 리스트에 인덱스==arr값 1씩 증가
for i in range(len(cnt)):
    for j in range(cnt[i]):
        print(i,end=' ') # 등장 횟수 만큼 출력