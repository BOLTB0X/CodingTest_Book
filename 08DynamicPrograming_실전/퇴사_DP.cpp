#include <iostream>

using namespace std;

int day[16];
int pay[16];
int dp[16] = { 0, };

//ÃÖ´ñ°ª ¹ÝÈ¯
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = 0;

	dp[0] = 0;
	for (int i = n; i >= 0; --i) {
		if (day[i] + i > n)
			dp[i] = dp[i + 1];
		else
			dp[i] = Max(dp[i + 1], pay[i] + dp[i + day[i]]);
	}
	
	answer = dp[0];
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