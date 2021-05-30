#유클리드 호제법으로 최대공약수 정의
def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)
#gcd를 이용하여 한 번 더 이용
def solution_gcd(a,b,c):
    return gcd(gcd(a,b),c)