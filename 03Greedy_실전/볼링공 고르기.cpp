#include <iostream>

using namespace std;

int solution(int n, int m, int* balls) {
	int answer = 0;
	int tmp = n; //임시
	int cnt[11] = { 0, };

	//번호별 카운트
	for (int i = 0; i < n; ++i) 
		cnt[balls[i]]++;
	
	for (int i = 1; i <= m; ++i) {
		tmp -= cnt[i];
		answer += (tmp * cnt[i]);
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
