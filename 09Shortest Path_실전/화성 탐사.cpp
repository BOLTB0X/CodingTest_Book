#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

typedef struct {
	int cost, y, x;
} heap;

struct compare {
	bool operator() (const heap& h1, const heap& h2) {
		return h1.cost < h2.cost; // ¿À¸§
	}
};

const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

void dijkstra(int n, vector<vector<int>>& board, vector<vector<int>>& dist) {
	priority_queue<heap, vector<heap>, compare> pq;
	pq.push({ -board[0][0], 0, 0 });
	dist[0][0] = board[0][0];

	while (!pq.empty()) {
		int ccost = -pq.top().cost;
		int cy = pq.top().y;
		int cx = pq.top().x;
		pq.pop();

		if (dist[cy][cx] < ccost)
			continue;
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			int ncost = ccost + board[ny][nx];
			if (ncost < dist[ny][nx]) {
				dist[ny][nx] = ncost;
				pq.push({ -ncost, ny, nx });
			}
		}
	}

	return;
}

int solution(int n, vector<vector<int>>& board) {
	int answer = 0;
	vector<vector<int>> dist(n, vector<int>(n, INF));

	dijkstra(n, board, dist);
	answer = dist[n - 1][n - 1];
	return answer;
}

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		int n;
		vector<vector<int>> board;

		cin >> n;
		board.resize(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cin >> board[i][j];
		}

		int ret = solution(n, board);
		cout << ret << '\n';
	}

	return 0;
}