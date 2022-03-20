#include <iostream>
#include <string>
using namespace std;

const int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int solution(string cmd) {
	int answer = 0;

	int y = cmd[1] - '1'; // 편의를 위한
	// '0'을 빼면 문제 조건상 1부터 시작하므로 편의를 위해 '1'을 빼줌
	int x = cmd[0] - 'a'; // 편의를 위한

	// 8방향 시뮬레이션 시작
	for (int dir = 0; dir < 8; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 범위 초과
		if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)
			continue;

		answer++;
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string cmd;
	//문자형+정수
	cin >> cmd;

	int ret = solution(cmd);
	cout << ret;
	return 0;
}
