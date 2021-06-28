#include <iostream>
using namespace std;

long long d[101]; //한 번 계산된 결과를 메모이제이션하기 위한 리스트 초기화

long long fibo(int x) {
	cout << "f(" << x << ")" << " ";
	//종료 조건
	if (x == 1 || x == 2) return 1;
	//계산한 적 있는 문제라면 그대로 리턴
	if (d[x] != 0) return d[x];
	//계산한 적 없는 문제라면 점화식에 따라 피보나치 결과 반환
	d[x] = fibo(x - 1) + fibo(x - 2);
	return d[x];
}

int main(void) {
	cout << fibo(50) << '\n';
	return 0;
}