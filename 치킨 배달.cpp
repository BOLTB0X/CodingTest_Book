#include <iostream>
#include <vector>

using namespace std;

int result = 0x7fffffff; //�ּڰ��� ����
int board[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> store;
vector<int> visited;

//���� ��ȯ
int Abs(int a) {
	return a < 0 ? -a : a;
}

//�ּڰ� ��ȯ
int Min(int a, int b) {
	return a < b ? a : b;
}

//ġģ�Ÿ�
int get_chicken_dist(int n, int hy, int hx) {
	int ret = 0x7fffffff; //�ּڰ��� ����

	for (int i = 0; i < store.size(); ++i) {
		//m�� ���͸�
		if (visited[i] == 1) {
			int dist = abs(store[i].first - hy) + abs(store[i].second - hx);
			ret = Min(ret, dist);
		}
	}

	if (ret == 0x7fffffff)
		ret = 0;

	return ret;
}

void DFS(int n, int m, int cur, int level) {
	//Ż������
	if (level == m) {
		int chicken_of_city_dist = 0;
		for (pair<int,int>& h : home) {
			int hy = h.first;
			int hx = h.second;
			chicken_of_city_dist += get_chicken_dist(n, hy, hx);
		}

		result = Min(result, chicken_of_city_dist);
		return;
	}

	for (int i = cur; i < store.size(); ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		DFS(n, m, i + 1, level + 1);
		visited[i] = 0;
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;

	//ġŲ�� �������� m�� ��ŭ �̾� �Ÿ��� �� �� �ּҰ� ���ϸ� ��
	visited.resize(store.size(), 0); //�湮����Ʈ �ʱ�ȭ
	DFS(n, m, 0, 0); //��Ʈ��ŷ���� ���� ����

	answer = result;
	return answer;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
			//��
			if (board[i][j] == 1)
				home.push_back({ i,j });

			//ġŲ��
			else if (board[i][j] == 2)
				store.push_back({ i,j });
		}
	}
	
	int ret = solution(n, m);
	cout << ret;
	return 0;
}