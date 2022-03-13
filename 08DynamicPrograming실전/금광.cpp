#include <iostream>

using namespace std;

int dp[1001][1001];
int board[1001][1001];

//최댓값
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int m) {
	int answer = -1;
	int left_up, left, left_down;
	//초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			dp[i][j] = board[i][j];
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			//첫번쨰일 경우
			if (j == 1)
				left_up = 0;
			else
				left_up = dp[j - 1][i - 1];

			if (j == n)
				left_down = 0;
			else
				left_down = dp[j + 1][i - 1];

			left = dp[j][i - 1];
			//최댓값
			dp[j][i] = dp[j][i] + Max(left_down, Max(left_up, left));
		}
	}

	for (int i = 1; i <= n; ++i) {
		answer = Max(answer, dp[i][m]);
	}

	return answer;
}

int main(void) {
	int T;
	int n, m;

	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) 
				cin >> board[i][j];
		}

		int ret = solution(n, m);
		cout << ret << '\n';
	}

	return 0;
}