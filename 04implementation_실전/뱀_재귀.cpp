#include <iostream>
#include <deque>

using namespace std;

typedef struct {
	int x;
	char c;
} Cmd;

typedef struct {
	int y, x;
} Snake;

int result = 0;
int board[101][101];
//상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

deque<Cmd> cmd; //명령어
deque<Snake> dq; //뱀

//방향 전환
int turn_dir(int d, char c) {
	if (c == 'L') {
		if (d == 0)
			return 3;
		else if (d == 1)
			return 2;
		else if (d == 2)
			return 0;
		else if (d == 3)
			return 1;
	}

	else {
		if (d == 0)
			return 2;
		else if (d == 1)
			return 3;
		else if (d == 2)
			return 1;
		else if (d == 3)
			return 0;
	}
}

//재귀 시뮬함수
void recursive_func(int n, int sec, int dir) {
	//몸길이를 늘려 -> 덱의 길이
	int ny = dq.front().y + dy[dir];
	int nx = dq.front().x + dx[dir];

	// 1. 종료 조건 -> 벽
	if (ny < 1 || nx < 1 || ny > n || nx > n) {
		result = sec;
		return;
	}

	// 2. 종료조건 -> 몸 중복
	for (int i = 0; i < dq.size(); ++i) {
		if (ny == dq[i].y && nx == dq[i].x) {
			result = sec;
			return;
		}
	}

	// 본격적 시작

	//사과를 발견한 겨우
	if (board[ny][nx] == 1) {
		board[ny][nx] = 0; //삭제
		dq.push_front({ ny,nx }); //머리
	}

	else {
		dq.pop_back(); //몸길이 변화 X
		dq.push_front({ ny,nx }); //머리
	}

	int n_dir = dir; //새로운 방향
	//명령 조건 발동
	if (cmd.size() != 0 && cmd.front().x == sec) {
		n_dir = turn_dir(n_dir, cmd.front().c);
		cmd.pop_front(); //삭제
	}

	//다음 시뮬 시작
	recursive_func(n, sec + 1, n_dir);
	return;
}

int solution(int n, int k, int l) {
	int answer = 0;

	// 종료조건 -> 벽에 부딫임, 몸이 부딫임
	// 범위초과, 덱원소가 중복
	// 뱀은 1,1에서 시작, 오른쪽 뱡향
	dq.push_back({ 1,1 });
	recursive_func(n, 1, 3); //재귀로 시뮬 시작
	answer = result;

	return answer;
}

int main(void) {
	int n, k, l;
	//맵
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			board[i][j] = 0;
	}

	//사과
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;

		cin >> a >> b;
		board[a][b] = 1; //사과 체크
	}
	
	//명령어
	cin >> l;
	for (int i = 0; i < l; ++i) {
		int a; 
		char b;

		cin >> a >> b;
		cmd.push_back({ a,b });
	}

	int ret = solution(n, k, l);
	cout << ret;

	return 0;
}