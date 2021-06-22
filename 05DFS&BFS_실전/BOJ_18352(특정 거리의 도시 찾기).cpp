#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
int n, m, k, x;

vector<vector<int> > graph; //도시정보
vector<int> dist; //거리정보
vector<int> result; //거리가 K인 도시


void bfs(int x) {
	int start = x; // X번 도시로부터 시작
	dist[x] = 0;
	queue<int> que;
	que.push(x);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (dist[next] == -1) { 
				dist[next] = dist[cur] + 1; 
				que.push(next); 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) 
			result.push_back(i);
	}
}
int main() {
	cin >> n >> m >> k >> x;
	graph = vector<vector<int> >(n + 1); 
	dist = vector<int>(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	bfs(x);
	if (result.size() != 0) {
		for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
	}
	else {
		cout << -1;
	}
	return 0;
}