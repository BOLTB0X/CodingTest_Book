#include <iostream>
using namespace std;

int n, m;
int map[50][50];
bool visited[50][50];
int result = 1;

//북동남서
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

//왼쪽으로 방향전환
int turn_dir(int d) {
	if (d == 0) 
		return 3;
	return d - 1;
}

void simulation(int x, int y, int dir) {
	int turn_cnt = 0;
	visited[x][y] = true;
	while (true) {
		//왼쪽방향부터 이동가능한지
		dir = turn_dir(dir);
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		//만약 육지이고 미방문이면
		if (map[nx][ny] == 0 && !visited[nx][ny]) {
			visited[nx][ny] = true;
			x = nx;
			y = ny;
			//이동 했으므로 
			result++;
			turn_cnt = 0;
			continue;
		}
		//갈 수 없다면
		else {
			turn_cnt++; //다음방향 탐색
		}
		//만약 4방향 모두 갈수 없다면
		if (turn_cnt == 4) {
			int nx = x - dx[dir];
			int ny = y - dy[dir];
			//육지일 겨웅
			if (map[nx][ny] == 0) {
				x = nx; 
				y = ny;
			}
			else
				break;
			turn_cnt = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, r, dir;
	
	cin >> n >> m;
	cin >> c >> r >> dir;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> map[x][y];
		}
	}
	simulation(c, r, dir);
	cout << result << '\n';
	return 0;
}
