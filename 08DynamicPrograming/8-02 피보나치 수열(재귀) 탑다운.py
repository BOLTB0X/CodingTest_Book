#결과를 메모이제이션하기 위한 리스트 초기화
d=[0]*100

#탑다운 다이나믹 프로그래밍
def fibo(x):
    #종료 조건
    if x==1 or x==2:
        return 1
    #이미 방문 했다면
    if d[x] != 0:
        return d[x]
    #아직 계산되지 않았다면
    d[x] = fibo(x-1)+fibo(x-2) #점화식에 따라 피보나치 결과 반환
    return d[x]
print(fibo(99))