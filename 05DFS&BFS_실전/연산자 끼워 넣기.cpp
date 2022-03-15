#include <iostream>

using namespace std;

long long res1 = -0x7fffffff; //최대를 위한
long long res2 = 0x7fffffff; //최소를 위한

int arr[12];
int op[4];

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
	return a < b ? a : b;
}

//백트래킹 이용
void DFS(int n, long long tot, int level) {
	if (level == n) {
		res1 = Max(res1, tot);
		res2 = Min(res2, tot);
		return;
	}

	else {
		if (op[0] > 0) {
			op[0]--;
			DFS(n, tot + arr[level], level + 1);
			op[0]++;
		}

		if (op[1] > 0) {
			op[1]--;
			DFS(n, tot - arr[level], level + 1);
			op[1]++;
		}

		if (op[2] > 0) {
			op[2]--;
			DFS(n, tot * arr[level], level + 1);
			op[2]++;
		}

		if (op[3] > 0) {
			op[3]--;
			DFS(n, (long long)tot / arr[level], level + 1);
			op[3]++;
		}
	}

	return;
}

pair<long long, long long> solution(int n) {
	pair<long long, long long> answer;

	DFS(n, arr[0], 1);

	answer.first = res1;
	answer.second = res2;

	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> op[0] >> op[1] >> op[2] >> op[3];

	pair<long long, long long> ret = solution(n);
	cout << ret.first << '\n';
	cout << ret.second << '\n';

	return 0;
}