#include <iostream>
#include <vector>
#define MS 100001 //최대길이
#define INF 1e9 //최댓값

using namespace std;

typedef struct {
	int next, cost;
} Node;

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정

//각 노드에 대한 정보를 담는 배열
vector<Node> adj[MS];
int visited[MS] = { 0, }; //방문리스트
vector<int> dist; //거리리스트

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
int get_Smallest_Node(int n) {
	int min_value = INF;
	int idx = 0; //가장 최단거리가 짧은 노드의 idx

	for (int i = 1; i <= n; ++i) {
		//짧은 거리 노드 발견하고 미방문이면
		if (dist[i] < min_value && visited[i] == 0) {
			min_value = dist[i];
			idx = i;
		}
	}

	return idx;
}

//다익스트라 알고리즘
void dijkstra(int n, int m, int start) {
	dist[start] = 0;
	visited[start] = 1;

	for (auto& node : adj[start]) 
		dist[node.next] = node.cost;
	
	//n-1개의 노드에 대해 반복
	for (int i = 0; i < n - 1; ++i) {
		// 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
		int cur = get_Smallest_Node(n);
		visited[cur] = 1;

		// 현재 노드와 연결된 다른 노드를 확인
		for (auto& node : adj[cur]) {
			int ncost = dist[cur] + node.cost;

			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (ncost < dist[node.next]) 
				dist[node.next] = ncost;
		}
	}

	return;
}

void print_answer(int n) {
	// 모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= n; i++) {
		// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
		if (dist[i] == INF) 
			cout << "INFINITY" << '\n';
		
		// 도달할 수 있는 경우 거리를 출력
		else 
			cout << dist[i] << '\n';
		
	}
	return;
}

void solution(int n, int m, int start) {
	dist.resize(MS, INF); // 최단 거리 테이블을 모두 무한으로 초기화

	//다익스트라 알고리즘을 수행
	dijkstra(n, m, start);
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, start;
	int a, b, c;
	
	cin >> n >> m >> start;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		
		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		adj[a].push_back({ b,c });
	}

	solution(n, m, start);

	print_answer(n);
	return 0;
}