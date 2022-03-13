#include <iostream>
#include <vector>
#define MS 300001 //최대 길이

using namespace std;

typedef struct {
	int idx, dist;
}Node;

Node que[MS];
int fr = 0, re = 0;
vector<int> graph[MS];

void enqueue(Node data) {
	que[re++] = data;
	return;
}

Node dequeue(void) {
	return que[fr++];
}

//너비우선 탐색
void BFS(int n, int x, vector<int>& dist) {
	enqueue({ x, 0 });
	dist[x] = 1;

	while (fr < re) {
		Node cur = dequeue();

		for (int& next : graph[cur.idx]) {
			//재방문 방지
			if (dist[next] != 0)
				continue;

			dist[next] = cur.dist + 1;
			enqueue({ next, cur.dist + 1 });
		}
	}

	return;
}

void solution(int n, int m, int k, int x) {
	int flag = 0;

	vector<int> dist(n + 1, 0); //거리리스트
	BFS(n, x, dist);

	for (int i = 1; i <= n; ++i) {
		//자기 자신 제외
		if (i == x)
			continue;

		if (dist[i] == k) {
			cout << i << '\n';
			flag = 1;
		}
	}

	if (flag == 0)
		cout << "-1";
	return;
}
int main(void) {
	int n, m, k, x;

	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		/*if (graph[a].size() > 1)
			sort(graph[a].begin(), graph[a].end());*/
	}

	solution(n, m, k, x);

	return 0;
}
