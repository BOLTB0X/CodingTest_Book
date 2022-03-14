#include <iostream>

using namespace std;

int result = -1;
int board[9][9];
int tmp[9][9]; //백업용

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

//백업
void backup(int n, int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			tmp[i][j] = board[i][j];
	}

	return;
}

void DFS(int n, int m, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//범위초과
		if (ny < 1 || nx < 1 || ny > n || nx > m)
			continue;
		
		//벽이거나 바이러스
		if (tmp[ny][nx] == 1 || tmp[ny][nx] == 2)
			continue;

		tmp[ny][nx] = 2;
		DFS(n, m, ny, nx);
	}

	return;
}

//최대 안전영역
int get_Safe_size(int n, int m) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (tmp[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void make_wall(int n, int m, int cnt) {
	if (cnt == 3) {
		//백업
		backup(n, m);

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (tmp[i][j] == 2)
					DFS(n, m, i, j);
			}
		}
	
		result = Max(result, get_Safe_size(n, m));
		return;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			//벽을 발견 -> 백트래킹
			if (board[i][j] == 0) {
				cnt++;
				board[i][j] = 1;
				make_wall(n, m, cnt);
				board[i][j] = 0;
				cnt--;
			}
		}
	}

	return;

}

int solution(int n, int m) {
	int answer = 0;

	make_wall(n, m, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m);
	cout << ret;

	return 0;
}
