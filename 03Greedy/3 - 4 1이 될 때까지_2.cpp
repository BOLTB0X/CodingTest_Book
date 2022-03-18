#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	int answer = 0;

	cin >> n >> k;

	while (1) {
		// N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기
		int target = (n / k) * k;
		answer += (n - target);

		n = target;
		//탈출 조건
		if (n < k)
			break;

		answer++;
		n /= k;
	}
	answer += (n - 1);
	cout << answer;
	return 0;
}