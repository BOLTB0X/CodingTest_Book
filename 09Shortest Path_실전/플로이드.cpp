#include <iostream>
#define INF 1e9

using namespace std;

int board[101][101];

int Min(int a, int b) {
	return a < b ? a : b;
}

//�ʱ�ȭ
void init(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			board[i][j] = INF;

			if (i == j)
				board[i][j] = 0;
		}
	}
	return;
}

void solution(int n, int m) {
	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	for (int k = 1; k <= n; ++k) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b)
				board[a][b] = Min(board[a][b], board[a][k] + board[k][b]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (board[i][j] == INF) //�������� ���� ���
				cout << 0 << ' ';
			else
				cout << board[i][j] << ' ';
		cout << '\n';
	}

	return;
}

int main(void) {
	int n, m;
	
	cin >> n >> m;
	init(n); //�ʱ�ȭ
	for (int i = 0; i < m; ++i) {
		int a, b, c;

		cin >> a >> b >> c;

		if (board[a][b] > c) 
			board[a][b] = c;
	}

	solution(n, m);

	return 0;
}