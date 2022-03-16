#include <iostream>

using namespace std;

int result = -1;
int day[16];
int pay[16];

//�ִ� ��ȯ
int Max(int a, int b) {
	return a > b ? a : b;
}

void DFS(int n, int cur_day, int tot, int add_pay) {
	//���������� �� ������ ���
	if (cur_day == n + 1) {
		result = Max(result, tot);
		return;
	}

	//�ʰ��ϴ� ���
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