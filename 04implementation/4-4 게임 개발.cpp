#include <iostream>
using namespace std;

int n, m;
int r, c, dir;
int map[50][50];
int dist[50][50];

int turn_left() {
	dir -= 1;
	if (dir == -1)
		dir = 3;
	return dir;
}

int simulation() {
	const int dr[4] = { -1,0,1,0 };
	const int dc[4] = { 0,1,0,-1 };
	
	int cnt = 1;
	int turn_cnt = 0;
	while (true) {
		turn_left();
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		
		if (dist[nr][nc] == 0 && map[nr][nc] == 0) {
			dist[nr][nc] = 1;
			r = nr;
			c = nc;
			cnt++;
			turn_cnt = 0;
			continue;
		}
		else 
			turn_cnt++;
		if (turn_cnt == 4) {
			nr = r - dr[dir];
			nc = c - dc[dir];
			if (map[nr][nc] == 0) {
				r = nr;
				c = nc;
			}
			else
				break;
			turn_cnt = 0;
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//맵 생성
	
	cin >> n >> m;
	cin >> r >> c >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int ret = simulation();
	cout << ret << '\n';
	return 0;
}
