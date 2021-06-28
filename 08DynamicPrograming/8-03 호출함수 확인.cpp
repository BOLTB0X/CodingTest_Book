#include <iostream>
using namespace std;

long long d[101]; //�� �� ���� ����� �޸������̼��ϱ� ���� ����Ʈ �ʱ�ȭ

long long fibo(int x) {
	cout << "f(" << x << ")" << " ";
	//���� ����
	if (x == 1 || x == 2) return 1;
	//����� �� �ִ� ������� �״�� ����
	if (d[x] != 0) return d[x];
	//����� �� ���� ������� ��ȭ�Ŀ� ���� �Ǻ���ġ ��� ��ȯ
	d[x] = fibo(x - 1) + fibo(x - 2);
	return d[x];
}

int main(void) {
	cout << fibo(50) << '\n';
	return 0;
}