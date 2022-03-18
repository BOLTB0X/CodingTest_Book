#include <iostream>

using namespace std;

int result;

int Max(int a, int b) {
	return a > b ? a : b;
}

// 백트래킹 
void DFS(int n, int* T, int* P, int level, int tot, int add_pay) {
	// 퇴사날까지 도달
	if (level == n + 1) {
		result = Max(result, tot);
		return;
	}

	// 넘겨버리는 경우
	if (level > n + 1) {
		result = Max(result, tot - add_pay);
		return;
	}

	for (int i = level; i <= n; ++i)
		DFS(n, T, P, i + T[i], tot + P[i], P[i]);

	return;
}


int solution(int n, int* T, int* P) {
	int answer = 0;
	result = -1;

	//백트래킹으로 하나씩 다 해봄
	DFS(n, T, P, 1, 0, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n;
	cin >> n;

	int* T = new int[n + 1];
	int* P = new int[n + 1];

	for (int i = 1; i <= n; ++i) 
		cin >> T[i] >> P[i];

	int ret = solution(n, T, P);
	cout << ret;
	
	delete[] T;
	delete[] P;
	return 0;
}
