#include <iostream>
#include <algorithm>

using namespace std;

int fears[100001]; // 공포도 배열

int solution(int n) {
	// 그리디 알고리즘
	// 모두 참여할 필요 X
	// 공포도 수치만큼 파티원 필요 -> for문으로 탐색하면서 파이원 수랑 공포도랑 같으면 정답 카운트
	int answer = 0;
	sort(fears, fears + n); // 오름차순 정렬
	int player_cnt = 0;

	for (int i = 0; i < n; ++i) {
		player_cnt++; // 카운트

		// 해당 공포도보다 플레이어 수가 이상이면
		if (fears[i] <= player_cnt) {
			answer++;
			player_cnt = 0;
		}
	}

	// 반환
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> fears[i];

	int ret = solution(n);
	cout << ret;

	return 0;
}
