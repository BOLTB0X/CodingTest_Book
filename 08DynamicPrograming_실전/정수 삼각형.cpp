#include <iostream>
#include <cstring>
using namespace std;

int triangle[501][501];
int dp[501][501];

int Max(int a, int b) {
	return a > b ? a : b;
}

void do_dynamic(int n) {
	//초기화
	for (int i = 0; i <= n; ++i)
		memset(dp[i], 0, n);

	//셋팅
	dp[1][1] = triangle[1][1];

	//보텀업
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) 
			dp[i][j] = triangle[i][j] + Max(dp[i - 1][j], dp[i - 1][j - 1]);
	}
	return;
}

int solution(int n) {
	int answer = -1;
	do_dynamic(n);

	for (int i = 1; i <= n; ++i)
		answer = Max(answer, dp[n][i]);

	return answer;
}

int main(void) {
	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			cin >> triangle[i][j];
	}

	int ret = solution(n);
	cout << ret;
	return 0;
}