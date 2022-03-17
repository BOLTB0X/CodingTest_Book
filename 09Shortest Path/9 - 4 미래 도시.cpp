#include <iostream>
#include <cstring>
#define INF 1e9 // 최댓값 셋팅

using namespace std;

int adj[101][101];

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

//인접행렬 초기화
void init(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				adj[i][j] = 0;
			else
				adj[i][j] = INF;
		}
	}
	return;
}

int solution(int n, int m, int x, int k) {
	int answer = 0;

	//플로이드 이용
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) 
				adj[j][k] = Min(adj[j][k], adj[j][i] + adj[i][k]);
		}
	}

	answer = adj[1][k] + adj[k][x];

	if (answer > INF)
		answer = -1;

	return answer;
}

int main(void) {
	int n, m, x, k;
	cin >> n >> m;

	init(n); //인접행렬
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;

		// 1, 양방향이고
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	cin >> x >> k;
	int ret = solution(n, m, x, k);
	cout << ret;

	return 0;
}
