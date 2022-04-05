#include <iostream>
#include <vector>
#include <algorithm>
#define Max_Size 100001

using namespace std;

struct Node {
	int cost, a, b;

	bool operator < (Node& n) {
		return cost < n.cost;
	}
};

int parent[Max_Size];
vector<Node> edges;

int find_Parent(int x) {
	if (x != parent[x])
		return parent[x] = find_Parent(parent[x]);
	return x;
}

void union_Parent(int a, int b) {
	a = find_Parent(a);
	b = find_Parent(b);

	if (a != b)
		parent[a] = b;

	return;
}

bool is_Same_Parent(int a, int b) {
	a = find_Parent(a);
	b = find_Parent(b);

	return a == b;
}

int solution(int n, int m) {
	int answer = 0;
	int last = 0;  // �ּ� ���� Ʈ���� ���ԵǴ� ���� �߿��� ���� ����� ū ����

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	sort(edges.begin(), edges.end());

	for (auto& edge : edges) {
		int ccost = edge.cost;
		int ca = edge.a;
		int cb = edge.b;

		// ����Ŭ�� �߻����� ���� ���
		if (!is_Same_Parent(ca, cb)) {
			union_Parent(ca, cb);
			answer += ccost;
			last = last > ccost ? last : ccost;
		}
	}

	return answer - last;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int cost, a, b;

		cin >> a >> b >> cost;
		edges.push_back({ cost, a, b });
	}

	int ret = solution(n, m);
	cout << ret;

	return 0;
}