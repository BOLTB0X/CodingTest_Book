#실전2 부품찾기 (4)집합 자료형 이용
n=int(input())
n_arr=set(map(int,input().split()))

m=int(input())
m_arr=list(map(int,input().split()))

for x in m_arr:
    if x in n_arr:
        print('yes',end=' ')
    else:
        print('no', end=' ')