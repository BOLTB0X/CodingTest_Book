#include <iostream>

using namespace std;

int board[21][21];
int dp[21][21];

// 최댓값
int Max(int a, int b) {
	return a > b ? a : b;
}

// 다이나믹 프로그래밍
int solution(int n, int m) {
	int answer = 0;
	int step1, step2, step3;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <=m; ++j) 
			dp[i][j] = board[i][j];
	}

	// 보텀업
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			// 오른쪽 위
			if (j == 1)
				step1 = 0;
			else
				step1 = dp[j - 1][i - 1];
			
			// 오른쪽 아래
			if (j == n)
				step3 = 0;
			else
				step3 = dp[j + 1][i - 1];
			
			// 오른쪽
			step2 = dp[j][i - 1];

			dp[j][i] = dp[j][i] + Max(step1, Max(step2, step3));
		}
	}

	for (int i = 1; i <= n; ++i)
		answer = Max(answer, dp[i][m]);
	return answer;
}

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				cin >> board[i][j];
		}
		
		int ret = solution(n, m);
		cout << ret << '\n';
	}

	return 0;
}
