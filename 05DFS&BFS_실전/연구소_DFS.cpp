#include <iostream>

using namespace std;

int result = -1;
int board[9][9];
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 깊이우선탐색
void DFS(int n, int m, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		if (board[ny][nx] == 1 || board[ny][nx] == 2)
			continue;

		board[ny][nx] = 2;
		DFS(n, m, ny, nx);
	}

	return;
}

// 안전지대갯수
int get_Safe_Area(int n, int m) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void make_Wall(int n, int m, int level) {
	if (level == 3) {
		int tmp_board[9][9];
		// 복사
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) 
				tmp_board[i][j] = board[i][j];
		}

		// 바이러스 확산
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 2)
					DFS(n, m, i, j);
			}
		}
		int tmp = get_Safe_Area(n, m);
		if (result < tmp)
			result = tmp;
		// 복원
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				board[i][j] = tmp_board[i][j];
		}

		return;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				make_Wall(n, m, level + 1);
				board[i][j] = 0;
			}
		}
	}

	return;
}

int solution(int n, int m) {
	int answer = 0;

	make_Wall(n, m, 0);
	answer = result;

	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
