#include <iostream>
#include <vector>
#include <queue>
#define Max_Size 300001

using namespace std;

vector<int> adj[Max_Size];
vector<int> visited;

vector<int> solution(int n, int m, int k, int x) {
	vector<int> answer;
	queue<int> que;
	visited.resize(n + 1, 0); // 방문리스트 초기화

	visited[x] = 1;
	que.push(x);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int& next : adj[cur]) {
			if (visited[next] != 0)
				continue;
			visited[next] = visited[cur] + 1;
			que.push(next);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (visited[i] - 1 == k)
			answer.push_back(i);
	}

	if (answer.size() == 0)
		answer.push_back(-1);
	return answer;
}

int main(void) {
	int n, m, k, x;

	cin >> n >> m >> k >> x;
	
	for (int i = 0; i < m; ++i) {
		int a, b;

		cin >> a >> b;
		adj[a].push_back(b);
	}

	vector<int> ret = solution(n, m, k, x);
	for (int& r : ret)
		cout << r << "\n";

	return 0;
}
