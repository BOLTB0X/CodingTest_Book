from collections import deque
from typing import Union
n,l,r=map(int,input().split()) #N,L,R 값 입력받기
graph=[]

for _ in range(n):
    graph.append(list(map(int,input().split())))

dx=[-1,0,1,0]
dy=[0,1,0,-1]

result=0

def BFS(x,y,index):
    united=[(x,y)] # (x,y)의 위치와 연결된 연합 정보를 담는 리스트
    que=deque()
    que.append((x,y))
    union[x][y]=index # 현재 연합의 번호 할당
    summary=graph[x][y] # 현재 연합의 전체 인구 수
    count = 1 # 현재 연합의 국가 수
    while que:
        x,y=que.popleft()
        
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0 <= nx < n and 0 <= ny < n and union[nx][ny] == -1:
                #옆에 있는 나라와 인구 차이가 L명 이상, R명 이하라면
                if l <= abs(graph[nx][ny] - graph[x][y]) <=r:
                    que.append((nx,ny))
                    #연합에 추가
                    union[nx][ny]=index
                    summary += graph[nx][ny]
                    count += 1
                    united.append((nx,ny))
        #연합 국가끼리 인구를 분배
    for i,j in united:
        graph[i][j] = summary // count
    return count

tot_count=0

while True:
    union = [[-1] * n for _ in range(n)]
    index=0

    for i in range(n):
        for j in range(n):
            if union[i][j] == -1: # 해당 나라가 아직 처리 
                BFS(i,j,index)
                index+=1

    # 모든 인구 이동이 끝난 경우
    if index == n*n:
        break
    tot_count += 1

print(tot_count)