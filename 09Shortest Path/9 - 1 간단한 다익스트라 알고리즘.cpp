#include <iostream>
#include <vector>
#define MS 100001 //�ִ����
#define INF 1e9 //�ִ�

using namespace std;

typedef struct {
	int next, cost;
} Node;

// ����� ����(N), ������ ����(M), ���� ��� ��ȣ(Start)
// ����� ������ �ִ� 100,000����� ����

//�� ��忡 ���� ������ ��� �迭
vector<Node> adj[MS];
int visited[MS] = { 0, }; //�湮����Ʈ
vector<int> dist; //�Ÿ�����Ʈ

// �湮���� ���� ��� �߿���, ���� �ִ� �Ÿ��� ª�� ����� ��ȣ�� ��ȯ
int get_Smallest_Node(int n) {
	int min_value = INF;
	int idx = 0; //���� �ִܰŸ��� ª�� ����� idx

	for (int i = 1; i <= n; ++i) {
		//ª�� �Ÿ� ��� �߰��ϰ� �̹湮�̸�
		if (dist[i] < min_value && visited[i] == 0) {
			min_value = dist[i];
			idx = i;
		}
	}

	return idx;
}

//���ͽ�Ʈ�� �˰���
void dijkstra(int n, int m, int start) {
	dist[start] = 0;
	visited[start] = 1;

	for (auto& node : adj[start]) 
		dist[node.next] = node.cost;
	
	//n-1���� ��忡 ���� �ݺ�
	for (int i = 0; i < n - 1; ++i) {
		// ���� �ִ� �Ÿ��� ���� ª�� ��带 ������, �湮 ó��
		int cur = get_Smallest_Node(n);
		visited[cur] = 1;

		// ���� ���� ����� �ٸ� ��带 Ȯ��
		for (auto& node : adj[cur]) {
			int ncost = dist[cur] + node.cost;

			// ���� ��带 ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
			if (ncost < dist[node.next]) 
				dist[node.next] = ncost;
		}
	}

	return;
}

void print_answer(int n) {
	// ��� ���� ���� ���� �ִ� �Ÿ��� ���
	for (int i = 1; i <= n; i++) {
		// ������ �� ���� ���, ����(INFINITY)�̶�� ���
		if (dist[i] == INF) 
			cout << "INFINITY" << '\n';
		
		// ������ �� �ִ� ��� �Ÿ��� ���
		else 
			cout << dist[i] << '\n';
		
	}
	return;
}

void solution(int n, int m, int start) {
	dist.resize(MS, INF); // �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ

	//���ͽ�Ʈ�� �˰����� ����
	dijkstra(n, m, start);
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, start;
	int a, b, c;
	
	cin >> n >> m >> start;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		
		// a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
		adj[a].push_back({ b,c });
	}

	solution(n, m, start);

	print_answer(n);
	return 0;
}