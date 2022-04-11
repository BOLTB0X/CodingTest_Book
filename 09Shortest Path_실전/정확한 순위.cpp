#include <iostream>
#include <vector>
#define INF 1e9 // 10억으로 무한대 설정

using namespace std;

int adj[501][501];

int Min(int a, int b) {
	return a < b ? a : b;
}

// 초기화
void init(int n) {
	// 무한대로 초기화
	for (int i = 0; i < 501; ++i) 
		fill(adj[i], adj[i] + 501, INF);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				adj[i][j] = 0;
		}
	}

	return;
}

int solution(int n, int m) {
	int answer = 0;

	// 플로이드
	for (int k = 1; k <= n; ++k) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b)
				adj[a][b] = Min(adj[a][b], adj[a][k] + adj[k][b]);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			// 양방향으로 무한대가 아니면
			// 비교를 한 것
			if (adj[i][j] != INF || adj[j][i] != INF)
				cnt++;
		}

		if (cnt == n)
			answer++;
	}

	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	init(n);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		adj[a][b] = 1;
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
