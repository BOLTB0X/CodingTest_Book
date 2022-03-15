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
//�����¿�
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

deque<Cmd> cmd; //��ɾ�
deque<Snake> dq; //��

//���� ��ȯ
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

//��� �ù��Լ�
void recursive_func(int n, int sec, int dir) {
	//�����̸� �÷� -> ���� ����
	int ny = dq.front().y + dy[dir];
	int nx = dq.front().x + dx[dir];

	// 1. ���� ���� -> ��
	if (ny < 1 || nx < 1 || ny > n || nx > n) {
		result = sec;
		return;
	}

	// 2. �������� -> �� �ߺ�
	for (int i = 0; i < dq.size(); ++i) {
		if (ny == dq[i].y && nx == dq[i].x) {
			result = sec;
			return;
		}
	}

	// ������ ����

	//����� �߰��� �ܿ�
	if (board[ny][nx] == 1) {
		board[ny][nx] = 0; //����
		dq.push_front({ ny,nx }); //�Ӹ�
	}

	else {
		dq.pop_back(); //������ ��ȭ X
		dq.push_front({ ny,nx }); //�Ӹ�
	}

	int n_dir = dir; //���ο� ����
	//��� ���� �ߵ�
	if (cmd.size() != 0 && cmd.front().x == sec) {
		n_dir = turn_dir(n_dir, cmd.front().c);
		cmd.pop_front(); //����
	}

	//���� �ù� ����
	recursive_func(n, sec + 1, n_dir);
	return;
}

int solution(int n, int k, int l) {
	int answer = 0;

	// �������� -> ���� �΋H��, ���� �΋H��
	// �����ʰ�, �����Ұ� �ߺ�
	// ���� 1,1���� ����, ������ ����
	dq.push_back({ 1,1 });
	recursive_func(n, 1, 3); //��ͷ� �ù� ����
	answer = result;

	return answer;
}

int main(void) {
	int n, k, l;
	//��
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			board[i][j] = 0;
	}

	//���
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;

		cin >> a >> b;
		board[a][b] = 1; //��� üũ
	}
	
	//��ɾ�
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