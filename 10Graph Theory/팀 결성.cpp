#include <iostream>
#define Max_Size 100001

using namespace std;

int parent[Max_Size];

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

void solution(int n, int m) {
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		// ÇÕÄ¡±â
		if (a == 0)
			union_Parent(b, c);

		else if (a == 1) {
			if (find_Parent(b) == find_Parent(c))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return;
}

int main(void) {
	int n, m;

	cin >> n >> m;

	solution(n, m);
	return 0;
}