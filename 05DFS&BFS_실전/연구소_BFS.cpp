#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[9][9];
int tmp_map[9][9];

queue<pair<int,int>> q;
const int dr[4] = { -1,1,0,0 };
const int dc[4] = { 0,0,-1,1 };

int result = 0;

int max(int a, int b) {
	return a > b ? a : b;
}

bool is_range(int row, int col) {
	if (row <1 || col < 1 || row >n || col >m)
		return false;
	return true;
}

void BFS() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (is_range(nr, nc)) {
				if (tmp_map[nr][nc] == 1 || tmp_map[nr][nc] == 2)
					continue;
				tmp_map[nr][nc] = 2;
				q.push({ nr,nc });
			}
		}
		
	}
}

void copy_map(int(*from)[9], int(*to)[9]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			to[i][j] = from[i][j];
		}
	}
	return;
}

int get_score() {
	int score = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tmp_map[i][j] == 0)
				score++;
		}
	}
	return score;
}

void make_wall(int cnt) {
	if (cnt == 3) {
		copy_map(map, tmp_map);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 2) {
					q.push({ i,j });
				}
			}
		}
		BFS();
		result = max(result, get_score());
		return;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				cnt++;
				map[i][j] = 1;
				make_wall(cnt);
				cnt--;
				map[i][j] = 0;
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
	//벽 시뮬 시작
	make_wall(0);

	cout << result << '\n';
	return 0;
}