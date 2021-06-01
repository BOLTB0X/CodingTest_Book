#성적이 낮은 순서로 학생 출력하기
n=int(input())
arr=[]
for i in range(n):
    name,score=input().split()
    arr.append((name,int(score)))
arr=sorted(arr,key=lambda x:x[1])
for x in arr:
    print(x[0],end=' ')