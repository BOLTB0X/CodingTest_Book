#include <iostream>

using namespace std;

int board[51][51];
int visited[51][51];

// 북동남서
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0 , 1, 0, -1 };

// 초기화
void init(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 0;
	}

	return;
}

// 왼쪽으로 회전
int turn_Left(int d) {
	if (d == 0)
		return 3;
	return d - 1;
}

// 범위
int in_Range(int n, int m, int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

// 솔루션
int solution(int n, int m, int a, int b, int d) {
	int answer = 1; // 현재 위치 고려
	int y = a, x = b;
	int play_cnt = 0;

	// 방문리스트 초기화
	init(n, m);

	// 차례대로 시뮬레이션 시작
	visited[y][x] = 1; // 방문 체크
	while (1) {
		d = turn_Left(d); // 회전
		int ny = y + dy[d];
		int nx = x + dx[d];

		// 범위 내
		if (in_Range(n, m, ny, nx) == 1) {
			// 미방문이고 육지이면
			if (visited[ny][nx] == 0 && board[ny][nx] == 0) {
				visited[ny][nx] = 1;
				y = ny, x = nx; // 변경
				answer++; // 카운트
				play_cnt = 0; // 초기화
				continue; // 다시 1단계로
			}

			else
				play_cnt++; // 다음방향 탐색

			// 4방향 탐색후 갈 때가 없다면
			if (play_cnt == 4) {
				// 뒤로 돌아감
				int ny = y - dy[d];
				int nx = x - dx[d];

				// 육지인 경우
				if (board[ny][nx] == 0)
					y = ny, x = nx;

				// 바다인 경우 -> 멈춤
				else
					break;

				play_cnt = 0; // 다시 초기화
			}
		}

		else
			continue;
	}
	
	return answer;
}

int main(void) {
	int n, m;
	int a, b, d;

	cin >> n >> m;
	cin >> a >> b >> d;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m, a, b, d);
	cout << ret;

	return 0;
}
