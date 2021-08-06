#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[1000][1000];
int n, m;

bool DFS(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	if (map[y][x] == 0) {
		map[y][x] = 1;
		DFS(y - 1, x);
		DFS(y, x - 1);
		DFS(y + 1, x);
		DFS(y, x + 1);
		return true;
	}
	return false;
}

int main() {
	int count = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (DFS(i,j)) count += 1;
		}
	}
	cout << count << endl;
	return 0;
}
