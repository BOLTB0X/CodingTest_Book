# 5-5 2가지 방식으러 구현한 팩토리얼 예제
def factorial_iterative(n):
    result=1
    for i in range(1,n+1): #반복문으로 범위 지정
        result*=i
    return result

def factorial_recursive(n):
    if n<=1:
        return 1
    return n*factorial_iterative(n-1) #재귀호출
print('for문 이용',factorial_iterative(5))
print('재귀문 이용',factorial_recursive(5))