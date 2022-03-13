from collections import deque
n,m,k,x=map(int,input().split()) #n은 정점 m노드 여기서 k는 거리 x는 출발
graph=[[] for _ in range(n+1)]  #index-1하지 않고 1로 하기 위해
for _ in range(m):
    a,b=map(int,input().split())
    if a==b:
        continue
    graph[a].append(b)
    graph[a].sort() #정렬 안 그럼 뒤죽박죽
visited=[False]*(n+1)
distance=[-1 for _ in range(n+1)]
distance[x]=0 #스타트
def bfs(x):
    que=deque([x])
    while que:
        cur=que.popleft()
        visited[cur]=True
        for next in graph[cur]:
            if visited[next]==False and distance[next]==-1: #미방문이면
                que.append(next)
                distance[next]=distance[cur]+1 #즉 첫 방문이면 1 두번째면 2
bfs(x)
answer=[]
for i in range(1,n+1):
    if distance[i]==k: #k와 같으면 정답 리스트에 담는다.
        answer.append(i)
answer.sort()
if len(answer)==0:
    print(-1)
else:
    for ans in answer:
        print(ans)
