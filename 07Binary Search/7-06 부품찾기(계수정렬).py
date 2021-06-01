#실전2 부품찾기 (3)계수정렬
n=int(input())
n_arr=[0]*1000001
for i in input().split():
    n_arr[int(i)]=1 #카운팅 +=1이 아닌 이유는 중복X

m=int(input())
m_arr=list(map(int,input().split()))
for x in m_arr:
    if n_arr[x]==1:
        print('yes',end=' ')
    else:
        print('no',end=' ')