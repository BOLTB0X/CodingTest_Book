#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	int answer = 0;

	cin >> n >> k;

	while (1) {
		// N�� K�� ������ �������� ���� �� �������� 1�� ����
		int target = (n / k) * k;
		answer += (n - target);

		n = target;
		//Ż�� ����
		if (n < k)
			break;

		answer++;
		n /= k;
	}
	answer += (n - 1);
	cout << answer;
	return 0;
}