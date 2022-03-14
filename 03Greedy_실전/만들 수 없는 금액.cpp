#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int* coins) {
	int answer = 1; //1로 셋팅

	sort(coins, coins + n); //오름차순 정렬

	for (int i = 0; i < n; ++i) {
		//작은 금액은 만들수가 없음
		if (answer < coins[i])
			break;
		//그 외
		answer += coins[i];
	}
	
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
