#include <iostream>

using namespace std;

int solution(int n, int m, int* balls) {
	int answer = 0;
	int* cnt = new int[m + 1];
	for (int i = 0; i <= m; ++i)
		cnt[i] = 0;

	for (int i = 0; i < n; ++i)
		cnt[balls[i]]++;

	for (int i = 1; i <= m; ++i) {
		//b가 선택할 경우의 수
		n -= cnt[i];
		//a가 선택할 경우의 수 -> cnt[i]
		answer += (cnt[i] * n);
	}

	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	int* balls = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> balls[i];

	int ret = solution(n, m, balls);
	cout << ret;

	return 0;
}
