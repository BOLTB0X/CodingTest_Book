#include <iostream>

using namespace std;

int dp[30001] = { 0, }; // dp 테이블

int Min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int n;
	cin >> n;

	// 보텀업 방식
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1; // -1한 것로 +1 카우트

		if (i % 5 == 0) // 5로 나눠 떨어지면
			dp[i] = Min(dp[i], dp[i / 5] + 1);

		if (i % 3 == 0) // 3로 나눠 떨어지면
			dp[i] = Min(dp[i], dp[i / 3] + 1);

		if (i % 2 == 0) // 2로 나눠 떨어지면
			dp[i] = Min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] << '\n';
	return 0;
}
