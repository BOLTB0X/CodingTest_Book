#include <iostream>

using namespace std;

int result = -1;
int day[16];
int pay[16];

//최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

void DFS(int n, int cur_day, int tot, int add_pay) {
	//마지막날에 딱 도착한 경우
	if (cur_day == n + 1) {
		result = Max(result, tot);
		return;
	}

	//초과하는 경우
	else if (cur_day > n + 1) {
		result = Max(result, tot - add_pay);
		return;
	}

	for (int i = cur_day; i <= n; ++i)
		DFS(n, i + day[i], tot + pay[i], pay[i]);
	return;
}

int solution(int n) {
	int answer = 0;

	DFS(n, 1, 0, 0);
	answer = result;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) 
		cin >> day[i] >> pay[i];
	
	int ret = solution(n);
	cout << ret;
	return 0;
}