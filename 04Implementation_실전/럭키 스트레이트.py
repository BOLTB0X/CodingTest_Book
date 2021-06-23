n=list(map(int,input()))
l=len(n)
ltot=0
rtot=0
for i in range(l//2):
    ltot+=n[i]
for j in range(l//2,l):
    rtot+=n[j]
if ltot==rtot:
    print('LUCKY')
else:
    print('READY')