#include <iostream>

using namespace std;

int board[21][21];
int dp[21][21];

//�ִ�
int Max(int a, int b) {
	return a > b ? a : b;
}

//���̳��� ���α׷���
int do_Dynaminc(int n, int m) {
	int answer = 0;

	//�ʱ�ȭ
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			dp[i][j] = board[i][j];
	}

	int move1, move2, move3; //���� �� ��, ������, ������ �Ʒ�
	
	//���Ҿ�
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			//������ ��
			if (j == 1)
				move1 = 0;
			else
				move1 = dp[j - 1][i - 1];

			//������ �Ʒ�
			if (j == n)
				move3 = 0;
			else
				move3 = dp[j + 1][i - 1];
			
			//������
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
	//�ʱ�ȭ
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
		//���̳��� 
		cout << do_Dynaminc(n, m) << '\n';
	}

	return 0;
}