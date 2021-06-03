#피보나치 재귀
def fibo(x):
    if x==1 or x==2:
        return 1
    else:
        return fibo(x-1)+fibo(x-2)
print(fibo(5))

#피보나치 반복
def fibo(x):
    arr=[]
    for i in range(x):
        if i<2:
            arr.append(1)
        else:
            arr.append(arr[i-1]+arr[i-2])
    return arr[x]
print(fibo(5))