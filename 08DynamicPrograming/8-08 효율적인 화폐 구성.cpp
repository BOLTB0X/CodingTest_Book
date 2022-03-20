#include <iostream>
#define MV 10001 // 최댓값
using namespace std;

int coins[101];
int dp[MV];

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int m) {
	int answer = -1;

	// dp테이블 초기화
	for (int i = 1; i <= m; ++i)
		dp[i] = MV;
	
	dp[0] = 0;
	// 보텀업
	for (int i = 1; i <= n; ++i) {
		int coin = coins[i]; // 사용할 동전
		for (int j = 1; j <= m; ++j) {
			if (dp[j - coin] >= 0) // 거슬러줄 수 있다면
				dp[j] = Min(dp[j], dp[j - coin] + 1);
		}
	}

	// 거슬러줄 수 있다면
	if (dp[m] != MV)
		answer = dp[m]; // 정답

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
