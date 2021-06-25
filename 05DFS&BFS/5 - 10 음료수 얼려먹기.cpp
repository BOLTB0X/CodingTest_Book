#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int graph[1000][1000];
int n, m;
bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	if (graph[x][y] == 0) {
		graph[x][y] = 1;
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	int count = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) count += 1;
		}
	}
	cout << count << endl;
}