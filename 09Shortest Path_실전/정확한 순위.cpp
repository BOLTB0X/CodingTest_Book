#include <iostream>
#define INF 1e9

using namespace std;

int graph[501][501];

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

void init(int n) {
	// 최단 거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; ++j)
			graph[i][j] = INF;
	}

	// 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b)
				graph[a][b] = 0;
		}
	}

	return;
}

int solution(int n, int m) {
	int answer = 0;
	int cnt = 0; // 카운트
	// 정확한 순위를 아는 학생 수를 알아야함

	// 점화식에 따라 플로이드 워셜 알고리즘을 수행
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = Min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] != INF || graph[j][i] != INF)
				cnt++;
		}
		// 헤딩 학생 행에서 카운트가 n이면
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

		graph[a][b] = 1;
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}