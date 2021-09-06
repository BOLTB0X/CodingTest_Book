#include <iostream>
using namespace std;

int n, m;
int map[9][9];
int tmp_map[9][9];
int result = 0;

const int dr[4] = { -1,1,0,0 };
const int dc[4] = { 0,0,-1,1 };

int max(int a, int b) {
	return a > b ? a : b;
}

//범위 체크
bool is_range(int row, int col) {
	if (row <1 || col <1 || row >n || col >m)
		return false;
	return true;
}

//바이러스 확산 DFS이용
void DFS(int row, int col) {
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (is_range(nr, nc)) {
			if (tmp_map[nr][nc] == 2 || tmp_map[nr][nc] == 1)
				continue;
			tmp_map[nr][nc] = 2;
			DFS(nr, nc);
		}
	}
	return;
}

//점수 득점
int get_score() {
	int score = 0;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			if (tmp_map[r][c] == 0) {
				score++;
			}
		}
	}
	return score;
}

//맵 복사
void copy_map(int(*from)[9], int(*to)[9]) {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			to[r][c] = from[r][c];
		}
	}
	return;
}

void make_wall(int cnt) {
	if (cnt == 3) {
		//바이러스 찾기
		copy_map(map, tmp_map);
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= m; c++) {
				if (tmp_map[r][c] == 2) {
					//바이러스 확산
					DFS(r, c);
				}
			}
		}
		result = max(result, get_score());
		return;
	}
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			//빈공간을 만다면
			//벽 짓고 부수기 반복
			if (map[r][c] == 0) {
				cnt++;
				map[r][c] = 1;
				make_wall(cnt);
				cnt--;
				map[r][c] = 0;
			}
		}
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//맵 생성
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	//벽 세우고 부수기 재귀로 반복
	make_wall(0);

	cout << result << '\n';
	return 0;
}