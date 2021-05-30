#5-10 음료수 얼려먹기
n,m=map(int,input().split())
ans=0
graph=[]
for _ in range(n):
    graph.append(list(map(int,input())))
def dfs(x,y):
    if x<=-1 or y<=-1 or x>=n or y>=m:
        return False
    if graph[x][y]==0:
        graph[x][y]=1
        dfs(x-1,y)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x,y+1)
        return True
    return False
for i in range(n):
    for j in range(m):
        if dfs(i,j)==True:
            ans+=1
print(ans)