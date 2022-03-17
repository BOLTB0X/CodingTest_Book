#include <iostream>

using namespace std;

int dp[1001] = { 0, }; //dp테이블 초기화
const int mod = 796796;

int main(void) {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; ++i) 
		dp[i] = (dp[i - 1] + ( 2 * dp[i - 2])) % mod;
	
	cout << dp[n];
	return 0;
}
