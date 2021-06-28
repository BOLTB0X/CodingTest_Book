#include <iostream>
using namespace std;

int x;

int fibo(int x) {
	if (x == 1 || x == 2) return 1;
	return fibo(x - 1) + fibo(x - 2);
}

int main(void) {
	cin >> x;
	cout << fibo(x) << '\n';
}