#8-3 호출되는 함수 확인
d=[0]*100
def fibonacci(x):
    print('f('+str(x)+')',end=' ')
    if x==1 or x==2:
        return 1
    if d[x]!=0:
        return d[x]
    d[x]=fibonacci(x-1) + fibonacci(x-2)
    return d[x]
fibonacci(6)