#include <iostream>
#define INF 1e9

using namespace std;

int graph[501][501];

// �ּڰ� ��ȯ
int Min(int a, int b) {
	return a < b ? a : b;
}

void init(int n) {
	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; ++j)
			graph[i][j] = INF;
	}

	// �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
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
	int cnt = 0; // ī��Ʈ
	// ��Ȯ�� ������ �ƴ� �л� ���� �˾ƾ���

	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
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
		// ��� �л� �࿡�� ī��Ʈ�� n�̸�
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