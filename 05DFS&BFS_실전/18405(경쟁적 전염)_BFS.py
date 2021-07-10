from collections import deque
dx=[-1,1,0,0]
dy=[0,0,-1,1]

def BFS(t,n):
    while que:
        virus,sec,x,y=que.popleft()
        if t==sec:
            break
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]

            if 0<=nx<n and 0<=ny<n: #범위에 해당
                if graph[nx][ny]==0: #비어있다면
                    graph[nx][ny]=virus
                    que.append((virus,sec+1,nx,ny)) #해당 바이러스로 1초 후 호출

n,k=map(int,input().split()) #n은 행,열 k바이러스 종류 수
graph=[] 
info=[] #바이러스 종류, 시간, 행,열을 담을 리스트

for i in range(n):
    graph.append(list(map(int,input().split())))
    for j in range(n):
        if graph[i][j]!=0: #빈공간이 아니라면
            info.append((graph[i][j],0,i,j)) #바이러스 종류,시간,행,열
info.sort()
que=deque(info)

t,row,col=map(int,input().split())
BFS(t,n)
print(graph[row-1][col-1])