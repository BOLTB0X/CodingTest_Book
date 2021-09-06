#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
vector<vector<int>> graph;
vector<int> dist;
vector<int> result;

void BFS(int start) {
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	//dist의 거리 정보를 result에 담음
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k)
			result.push_back(i);
	}
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//그래프 생성
	cin >> n >> m >> k >> x;
	graph = vector<vector<int>> (n + 1);
	dist = vector<int>(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	//BFS실행
	BFS(x);
	
	if (result.size() != 0) {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << '\n';
	}
	else cout << -1 << '\n';
	return 0;
}