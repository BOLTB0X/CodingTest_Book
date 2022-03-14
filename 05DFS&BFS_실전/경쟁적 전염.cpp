#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int y, x, sec, idx;
} Virus; //바이러스

Virus que[200001];
int fr = 0, re = 0;

void enqueue(Virus data) {
	que[re++] = data;
	return;
}

Virus dequeue(void) {
	return que[fr++];
}

vector<vector<int>> board;
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//비교
int compare(Virus& a, Virus& b) {
	return a.idx < b.idx;
}

//너비우선
void BFS(int n, int k, int s) {
	while (fr < re) {
		Virus cur = dequeue();

		if (cur.sec == s)
			return;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위 초과
			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;

			//확산 가능 범위 발견
			if (board[ny][nx] == 0) {
				board[ny][nx] = cur.idx;
				enqueue({ ny, nx, cur.sec + 1, cur.idx });
			}
		}
	}

	return;
}

int solution(int n, int k, int s, int y, int x) {
	int answer = 0;
	vector<Virus> v; //바이러스
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (board[i][j] != 0)
				v.push_back({ i,j,0,board[i][j] });
	}

	//바이러스 번호가 낮은 것부터 확산 됌
	sort(v.begin(), v.end(), compare);

	//큐에 삽입
	for (Virus& t_v : v) 
		enqueue(t_v);

	BFS(n, k, s);

	if (board[y][x] != 0)
		answer = board[y][x];

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int s, y, x;

	cin >> n >> k;
	board.resize(n + 1, vector<int>(n + 1, 0));
	//맵 생성
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];
	}

	cin >> s >> y >> x;

	int ret = solution(n, k, s, y, x);
	cout << ret;

	return 0;
}
