st=input()
alp=''
num=0
for s in st:
    if s.isalpha():
        alp+=s
    elif s.isalnum():
        num+=int(s);
answer=sorted(alp)
answer.append(str(num))
print(''.join(answer))