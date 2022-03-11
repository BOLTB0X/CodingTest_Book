#include <iostream>
#include <vector>
#define INF 1e9 //10억

using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}

//플로이드 
void floyed(vector<vector<int>>& adj, int n) {
	//점화식
	for (int k = 1; k <= n; ++k) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b)
				adj[a][b] = Min(adj[a][b], adj[a][k] + adj[k][b]);
		}
	}

	return;
}

int solution(vector<pair<int, int>> &edge, int n, int m, int x, int k) {
	int answer = 0;
	//1 - > k,  k -> x;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF)); //인접행렬 INF로 초기화

	//먼저 인접행렬로 자기 자신한테 가는 비용 초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				adj[i][j] = 0;
		}
	}

	//연결 여부 
	for (pair<int, int>& e : edge) {
		adj[e.first][e.second] = 1;
		adj[e.second][e.first] = 1;
	}

	floyed(adj, n);

	answer = (adj[1][k] + adj[k][x]) < INF ? (adj[1][k] + adj[k][x]) : -1;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, k;
	vector<pair<int, int>> edge;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		edge.push_back({ a,b });
	}

	cin >> x >> k;

	int ret = solution(edge, n, m, x, k);
	cout << ret;
	return 0;
}
