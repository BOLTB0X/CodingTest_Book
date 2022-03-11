#include <iostream>
#include <vector>
#define MS 100001 //최대길이
#define INF 1e9 //최댓값

using namespace std;

typedef struct {
	int target, cost;
} Node;

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정

//각 노드에 대한 정보를 담는 배열
vector<Node> adj[MS];
int visited[MS] = { 0, }; //방문리스트
vector<int> dist; //거리리스트

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
int get_Shortest_Node(int n) {
	int min_value = INF;
	int idx = 0; //가장 최단 거리가 짧은 노드 idx

	for (int i = 1; i <= n; ++i) {
		//미방문이고 짧은 거리를 가진 노드이면
		if (visited[i] == 0 && dist[i] < min_value) {
			min_value = dist[i];
			idx = i;
		}
	}

	return idx;
}

//다익스트라 알고리즘 - > 여러 개의 노드가 있을 때 특정 노드 출발에서 각 노드의 최단경로를 구해줌
void dijkstra(int n, int m, int start) {
	//시작 노드
	dist[start] = 0;
	visited[start] = 1;

	//스타트에 연결된 노드의 거리 리스트에 거리 비용을 넣어줌
	for (Node& next : adj[start]) 
		dist[next.target] = next.cost;
	
	//n - 1반복
	for (int i = 0; i < n - 1; ++i) {
		//현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문처리
		int cur = get_Shortest_Node(n);
		visited[cur] = 1;

		//다시 반복
		for (Node& next : adj[cur]) {
			int ncost = dist[cur] + next.cost;

			//현재 노드를 거쳐서 다른 노드로 이동하는 거리
			if (ncost < dist[next.target])
				dist[next.target] = ncost;
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
