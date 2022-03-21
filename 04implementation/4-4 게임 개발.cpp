#include <iostream>

using namespace std;

int board[51][51];
int visited[51][51];

// 북동남서
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

// 왼쪽 90도로 회전
int turn_Left(int d) {
	// 북쪽일 경우
	if (d == 0)
		return 3; //서
	return d - 1;
}

// 초기화
void init(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 0;
	}

	return;
}

int solution(int n, int m, int a, int b, int d) {
	int answer = 1; // 시작 위치도 포함이므로
	int y = a, x = b; // y,x,d 만들어 둠
	int play_cnt = 0; // 최대 4방향 플레이 카운트
	
	init(n, m); // 방문리스트 초기화
	visited[y][x] = 1; // 스타트
	while (1) {
		// 1번 조건부터 차례로
		d = turn_Left(d); 
		int ny = y + dy[d];
		int nx = x + dx[d];

		// 범위 안이면
		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			// 2번 조건
			if (visited[ny][nx] == 0 && board[ny][nx] == 0) {
				visited[ny][nx] = 1;
				play_cnt = 0; // 최대 4방향 플레이 카운트 초기회
				answer++; // 카운트
				y = ny, x = nx; // 교체
				continue; // 다음으로 넘어감
			}

			// 다시 1단계로
			else 
				play_cnt++; // 카운트

			// 4방향 모두 돌았는데 나아갈 방향이 없다면
			if (play_cnt == 4) {
				// 후진
				ny = y - dy[d];
				nx = x - dx[d];

				// 육지라면
				if (board[ny][nx] == 0) 
					y = ny, x = nx; // 교체
				
				// 바다이면
				else
					break;
				
				play_cnt = 0; // 초기화
			}
		}
		else
			continue;
	}

	return answer;
}

int main(void) {
	int n, m, a, b, d;

	cin >> n >> m;
	cin >> a >> b >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j]; // 육지는 0, 바다는 1
	}

	int ret = solution(n, m, a, b, d);
	cout << ret;

	return 0;
}
