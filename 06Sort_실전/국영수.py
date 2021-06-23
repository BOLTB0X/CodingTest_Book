t=int(input())
imf=[]
for i in range(t):
    student,kor,eng,mat=input().split()
    imf.append([student,int(kor),int(eng),int(mat)])
imf.sort(key = lambda x: (-x[1],x[2],-x[3],x[0]))
for im in imf:
    print(im[0])