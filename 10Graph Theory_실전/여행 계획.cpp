#include <iostream>
#include <vector>

using namespace std;

int board[501][501];
vector<int> parent(501, 0);

int find_Parent(int x) {
	if (x == parent[x])
		return x;

	return parent[x] = find_Parent(parent[x]);
}

void union_Parent(int a, int b) {
	a = find_Parent(a);
	b = find_Parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;

	return;
}

string solution(int n, int m, vector<int>& plans) {
	string answer = "NO";
	int flag = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (board[i][j] == 1)
				union_Parent(i + 1, j + 1);
	}

	for (int i = 0; i < m - 1; ++i) {
		if (find_Parent(plans[i]) != find_Parent(plans[i + 1]))
			flag = 0;
	}

	if (flag == 1)
		answer = "YES";

	return answer;
}

int main(void) {
	int n, m;
	vector<int> plans;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}

	plans.resize(m);
	for (int i = 0; i < m; ++i)
		cin >> plans[i];

	string ret = solution(n, m, plans);
	cout << ret;
	return 0;
}