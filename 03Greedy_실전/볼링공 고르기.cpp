#include <iostream>

using namespace std;

int solution(int n, int m, int* balls) {
	int answer = 0;
	int cnt[11] = { 0, };

	//해당 볼 카운트
	for (int i = 0; i < n; ++i) 
		cnt[balls[i]]++;
	
	for (int i = 1; i <= m; ++i) {
		n -= cnt[i];
		answer += (cnt[i] * n);
	}

	return answer;
}

int main(void) {
	int n, m;
	int balls[1001];

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> balls[i];

	int ret = solution(n, m, balls);
	cout << ret;

	return 0;
}