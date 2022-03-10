#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int* coins) {
	int answer = 0;
	int target = 1; //1�� ����

	sort(coins, coins + n); //���� ���� ����

	for (int i = 0; i < n; ++i) {
		//���� ���� ���� �� ���� �ݾ�
		if (target < coins[i])
			break;
		target += coins[i];
	}
	
	answer = target;
	return answer;
}

int main(void) {
	int n;
	int coins[1001];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> coins[i];

	int ret = solution(n, coins);
	cout << ret;

	return 0;
}