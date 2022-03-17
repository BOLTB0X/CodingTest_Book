#include <iostream>

using namespace std;

int dp[10001] = { 0, };
int coins[101];

int Min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> coins[i];

	for (int i = 1; i <= m; ++i)
		dp[i] = 10001; // 최댓값으로 초기화
	
	//보텀업
	for (int i = 1; i <= n; ++i) {
		int coin = coins[i]; // 해당 화폐
		for (int j = 1; j <= m; ++j) {
			if (j - coin >= 0) // 구성이 가능하다면
				dp[j] = Min(dp[j], dp[j - coin] + 1);
		}
	}
	
	if (dp[m] == 10001)
		cout << "-1";
	else
		cout << dp[m];

	return 0;
}
