n=int(input())
nums=list(map(int,input().split())) # 수들
add,sub,mul,div=map(int,input().split()) #연산자

min_value=1000000001 
max_value=-1000000001

def DFS(num,idx,add,sub,mul,div):
    global n,max_value,min_value #전역변수
    if idx == n: #인덱스가 도달하면
        max_value=max(num, max_value)
        min_value=min(num, min_value)
        return
    else: #조건별 재귀적 함수호출
        if add > 0:
            DFS(num + nums[idx], idx + 1, add - 1, sub, mul, div)
        if sub > 0:
            DFS(num - nums[idx], idx + 1, add, sub - 1, mul, div)
        if mul > 0:
            DFS(num * nums[idx], idx + 1, add, sub , mul -1, div)
        if div > 0:
            DFS(int(num / nums[idx]), idx + 1, add, sub, mul, div -1)

DFS(nums[0],1,add,sub,mul,div)
print(max_value)
print(min_value)