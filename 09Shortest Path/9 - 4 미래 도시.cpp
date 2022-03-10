#include <iostream>
#define INF 1e9

using namespace std;

int adj[101][101];

//최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

//초기화
void init(int n) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			adj[i][j] = INF;
	}
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			if (i == j)
				adj[i][j] = 0;
	}

	return;
}

int solution(int n, int m, int x, int k) {
	int answer = 0;

	for (int k = 1; k <= n; ++k) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b)
				adj[a][b] = Min(adj[a][b], adj[a][k] + adj[k][b]);
		}
	}

	int dist = adj[1][k] + adj[k][x];

	answer = dist >= INF ? -1 : dist;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, k;
	cin >> n >> m;

	init(n); //초기화

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	cin >> x >> k;
	int ret = solution(n, m, x, k);
	cout << ret;

	return 0;
}