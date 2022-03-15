#include <iostream>

using namespace std;

int board[21][21];
int dp[21][21];

//최댓값
int Max(int a, int b) {
	return a > b ? a : b;
}

//다이나믹 프로그래밍
int do_Dynaminc(int n, int m) {
	int answer = 0;

	//초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			dp[i][j] = board[i][j];
	}

	int move1, move2, move3; //오른 쪽 위, 오른쪽, 오른쪽 아래
	
	//보텀업
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			//오른쪽 위
			if (j == 1)
				move1 = 0;
			else
				move1 = dp[j - 1][i - 1];

			//오른쪽 아래
			if (j == n)
				move3 = 0;
			else
				move3 = dp[j + 1][i - 1];
			
			//오른쪽
			move2 = dp[j][i - 1];
			//dp
			dp[j][i] = dp[j][i] + Max(move1, Max(move2, move3));
		}
	}

	for (int i = 1; i <= n; ++i)
		answer = Max(answer, dp[i][m]);

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				cin >> board[i][j];
		}
		//다이나믹 
		cout << do_Dynaminc(n, m) << '\n';
	}

	return 0;
}