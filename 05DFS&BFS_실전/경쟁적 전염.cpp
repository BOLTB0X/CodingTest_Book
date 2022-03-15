#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int y, x, sec, idx;
} Virus;

Virus que[40001];
int fr = 0, re = 0;

void enqueue(Virus data) {
	que[re++] = data;
	return;
}

Virus dequeue(void) {
	return que[fr++];
}

int board[201][201];
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

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

			//범위초과
			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;

			if (board[ny][nx] == 0) {
				board[ny][nx] = cur.idx; //바이러스 표시
				enqueue({ ny,nx, cur.sec + 1, cur.idx });
			}
		}
	}

	return;
}

int solution(int n, int k, int s, int y, int x) {
	int answer = 0;
	Virus* virus = new Virus[n * n + 1];
	int v_idx = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			//바이러스 위치 
			if (board[i][j] != 0)
				virus[v_idx++] = { i,j,0, board[i][j] };
		}
	}

	sort(virus, virus + v_idx, compare); //작은 번호순으로 정렬
	//큐에 삽입
	for (int i = 0; i < v_idx; ++i) 
		enqueue(virus[i]);
	
	BFS(n, k, s);

	answer = board[y][x] != 0 ? board[y][x] : 0;

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int s, y, x;

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) 
			cin >> board[i][j];
	}

	cin >> s >> y >> x;

	int ret = solution(n, k, s, y, x);
	cout << ret;

	return 0;
}
