#4-4 게임개발
n,m=map(int,input().split())
d=[[0]*m for _ in range(n)] #방문 위치
x,y,dr=map(int,input().split())
d[x][y]=1

arr=[]
for i in range(n): #맵 생성
    arr.append(list(map(int,input().split())))
# 북 동 남 서
dx=[-1,0,1,0]
dy=[0,1,0,-1]
def turn_left():
    global dr
    dr-=1
    if dr ==-1:
        dr=3
cnt=1
turn_time=0
while True:
    turn_left()
    nx=x+dx[dr]
    ny=y+dx[dr]
    if d[nx][ny] ==0 and arr[nx][ny]==0:
        d[nx][ny]=1
        x=nx
        y=ny
        cnt+=1
        turn_time=0
        continue
    else:
        turn_time+=1
    if turn_time==4:
        nx=x-dx[dr]
        ny=y-dy[dr]
        if arr[nx][ny]==0:
            x=nx
            y=ny
        else:
            break
        turn_time=0
print(cnt)