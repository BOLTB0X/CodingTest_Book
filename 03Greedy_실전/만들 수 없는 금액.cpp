#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int* coins) {
	int answer = 0;
	int target = 1; //1로 시작

	sort(coins, coins + n); //오름 차순 정렬

	for (int i = 0; i < n; ++i) {
		//작은 경우는 나올 수 없는 금액
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