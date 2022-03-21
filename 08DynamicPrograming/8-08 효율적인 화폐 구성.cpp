#include <iostream>
#define Max_Value 10001
using namespace std;

int coins[101];
int dp[Max_Value];

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int m) {
	int answer = -1;
	// dp테이블 초기화
	dp[0] = 0;
	for (int i = 1; i <= m; ++i)
		dp[i] = Max_Value;

	// 보텀업방식
	for (int i = 1; i <= n; ++i) {
		int coin = coins[i]; // 사용할 동전
		for (int j = 1; j <= m; ++j) {
			if (j - coin >= 0)
				dp[j] = Min(dp[j], dp[j - coin] + 1);
		}
	}

	// 거슬러 줄수 있다면
	if (dp[m] != Max_Value)
		answer = dp[m];
	return answer;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> coins[i];

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
