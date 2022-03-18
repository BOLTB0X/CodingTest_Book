#include <iostream>

using namespace std;

int solution(int n, int k) {
	int answer = 0;

	while (1) {
		//1이 될떄까지
		int target = n / k;

		if (target == 0)
			break;

		answer += (n - (target * k));
		n = target;
		answer++;
	}

	answer += n - 1;

	return answer;
}
int main(void) {
	int n, k;

	cin >> n >> k;

	int ret = solution(n, k);
	cout << ret;
	return 0;
}
