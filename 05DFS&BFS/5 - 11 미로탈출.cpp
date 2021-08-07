#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[201][201];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int BFS(int y, int x) {
	queue<pair<int, int>> que;
	que.push({ y,x });

	while (!que.empty()) {
		int cur_y = que.front().first;
		int cur_x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 0 || ny >= n || nx<0 || nx>=m) 
				continue;
			if (map[ny][nx] == 0) 
				continue;
			if (map[ny][nx] == 1) {
				map[ny][nx] = map[cur_y][cur_x] + 1;
				que.push({ ny,nx });
			}
		}
	}
	return map[n - 1][m - 1];
}

int main(void) {
	cin >> n >> m;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	cout << BFS(0, 0)<< '\n';
	return 0;
}
