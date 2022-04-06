#include <iostream>
#include <cstring>

using namespace std;

int triangle[501][501];
int dp[501][501];

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

void do_dynamic(int n) {
	//초기화
	memset(dp, 0, n);
	//셋팅
	dp[0][0] = triangle[0][0];

	//보텀업
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			dp[i][j] = triangle[i][j] + Max(dp[i - 1][j], dp[i - 1][j - 1]);
	}
	return;
}

int solution(int n) {
	int answer = -1;
	do_dynamic(n);

	for (int i = 0; i < n; ++i)
		answer = Max(answer, dp[n - 1][i]);

	return answer;
}

int main(void) {
	int n;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			cin >> triangle[i][j];
	}

	int ret = solution(n);
	cout << ret;
	return 0;
}
