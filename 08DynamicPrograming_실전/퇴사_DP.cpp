#include <iostream>

using namespace std;

int day[16];
int pay[16];
int dp[16];

//최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = 0;

	// dp테이블 초기화
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	// 거꾸러
	for (int i = n; i >= 0; --i) {
		if (i + day[i] <= n) {
			dp[i] = Max(answer, dp[i + day[i]] + pay[i]);
			answer = dp[i];
		}
		else
			dp[i] = answer;
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) 
		cin >> day[i] >> pay[i];

	int ret = solution(n);
	cout << ret;
	return 0;
}
