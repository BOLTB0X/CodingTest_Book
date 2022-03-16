#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int y, x;
} Pair;

int flag = 0;
char board[7][7];
vector<Pair> teachers;
vector<Pair> space;

//상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//감시되는 확인
int check(int n, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y;
		int nx = x;

		//범위 내
		while (ny >= 1 && nx >= 1 && ny <= n && nx <= n) {
			//벽을 보게되면 멈춰도 됌
			if (board[ny][nx] == 'O')
				break;

			//학생을 보게 되면
			if (board[ny][nx] == 'S')
				return 0;

			ny += dy[dir];
			nx += dx[dir];
		}
	}
	return 1;
}

//백트래킹 이용
void DFS(int n, int cur, int level) {
	if (flag == 1)
		return;
	//3까지이니
	if (level == 3) {
		//선생님 방향 기준에서 학생이 있는지 없는지 체크
		for (Pair& t : teachers) {
			if (check(n, t.y, t.x) == 0) {
				return;
			}
		}

		//여기까지 온거면 답이 나온 것
		flag = 1;
		return;
	}

	for (int s = cur; s < space.size(); ++s) {
		int r = space[s].y;
		int c = space[s].x;

		board[r][c] = 'O';
		DFS(n, s + 1, level + 1);
		board[r][c] = 'X';
	}

	return;
}

//선생님 T, 학생 S, 장애물 O
string solution(int n) {
	string answer;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			//선생님 찾기
			if (board[i][j] == 'T')
				teachers.push_back({ i,j });

			//빈공간
			if (board[i][j] == 'X')
				space.push_back({ i,j });
		}
	}

	DFS(n, 0, 0);
	answer = flag == 1 ? "YES" : "NO";
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];
	}

	string ret = solution(n);
	cout << ret;

	return 0;
}