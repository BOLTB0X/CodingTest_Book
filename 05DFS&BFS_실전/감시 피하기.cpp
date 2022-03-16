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

//�����¿�
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//���õǴ� Ȯ��
int check(int n, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y;
		int nx = x;

		//���� ��
		while (ny >= 1 && nx >= 1 && ny <= n && nx <= n) {
			//���� ���ԵǸ� ���絵 ��
			if (board[ny][nx] == 'O')
				break;

			//�л��� ���� �Ǹ�
			if (board[ny][nx] == 'S')
				return 0;

			ny += dy[dir];
			nx += dx[dir];
		}
	}
	return 1;
}

//��Ʈ��ŷ �̿�
void DFS(int n, int cur, int level) {
	if (flag == 1)
		return;
	//3�����̴�
	if (level == 3) {
		//������ ���� ���ؿ��� �л��� �ִ��� ������ üũ
		for (Pair& t : teachers) {
			if (check(n, t.y, t.x) == 0) {
				return;
			}
		}

		//������� �°Ÿ� ���� ���� ��
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

//������ T, �л� S, ��ֹ� O
string solution(int n) {
	string answer;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			//������ ã��
			if (board[i][j] == 'T')
				teachers.push_back({ i,j });

			//�����
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