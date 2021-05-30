#-3-1 거스름돈
coin_type=[500,100,50,10]
n=int(input())
cnt=0
for coin in coin_type:
    cnt+=n//coin #해당 화폐로 거술러 줄 수 있는 동전의 개수
    n%=coin
print(cnt)