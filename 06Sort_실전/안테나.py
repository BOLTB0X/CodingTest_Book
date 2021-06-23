n=int(input())
home_loca=list(map(int,input().split()))
answer=[]
for loca in home_loca:
    tot=0
    for i in range(n):
        tot+=abs(loca-home_loca[i])
    answer.append([loca,tot])
answer.sort(key=lambda x: x[1])
print(answer[0][0])

n=int(input())
locas=list(map(int,input().split()))
locas.sort()
print(locas[(n-1)//2])