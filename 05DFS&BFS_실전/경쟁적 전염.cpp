#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct inf {
	int r, c, sec, vrius_idx;
};

int n, k;
int s, x, y; //x->row, y->col;
int map[201][201] = { 0, };
queue<inf> q;
const int dr[4] = { -1,1,0,0 };
const int dc[4] = { 0,0,-1,1 };

//���̷��� �������� ��������
bool compare(inf a, inf b) {
	return a.vrius_idx < b.vrius_idx;
}

//���� üũ
bool is_range(int row, int col) {
	if (row < 1 || col < 1 || row >n || col >n)
		return false;
	return true;
}

//BFS
int BFS(int sec, int row, int col) {
	while (!q.empty()) {
		inf cur = q.front();
		q.pop();
		//�ð��� �°� �Ǹ� Ż��
		if (sec == cur.sec)
			break;
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];

			if (is_range(nr, nc)) {
				//������ų �����̸�
				if (map[nr][nc] == 0) {
					map[nr][nc] = cur.vrius_idx;
					inf next;
					next.r = nr;
					next.c = nc;
					next.sec = cur.sec + 1;
					next.vrius_idx = cur.vrius_idx;
					q.push(next);
				}
			}
		}

	}
	return map[row][col];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<inf> priority_v;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0)
				//��ġ �ð� ���̷��� ����
				priority_v.push_back({ i,j,0,map[i][j] });
		}
	}
	//���̷��� ��ȣ �߽����� ��������
	sort(priority_v.begin(), priority_v.end(), compare);
	//ť�� ����
	for (int i = 0; i < priority_v.size(); i++)
		q.push(priority_v[i]);

	cin >> s >> x >> y;
	int ret = BFS(s, x, y);
	cout << ret << '\n';
	return 0;
}