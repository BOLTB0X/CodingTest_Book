#include <iostream>
#include <vector>
using namespace std;

int flag = 0;
char board[7][7];
//상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//체크
int check(int n, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		//범위 안이면 무한 반복
		while (ny >= 1 && nx >= 1 && ny <= n && nx <= n) {
			if (board[ny][nx] == 'O')
				break;
			
			if (board[ny][nx] == 'S')
				return 0;

			ny += dy[dir];
			nx += dx[dir];
		}
	}

	return 1;
}

void DFS(int n, vector<pair<int, int>>& s, vector<pair<int, int>>& t, int cur, int level) {
	//답이 나온 경우
	if (flag == 1)
		return;

	//탈출조건
	if (level == 3) {
		for (pair<int, int>& tmp_t : t) {
			int y = tmp_t.first;
			int x = tmp_t.second;

			//하나도 감시를 못피하면
			if (check(n, y, x) == 0)
				return;
		}
		flag = 1;
		return;
	}

	//중복조합구하듯이
	for (int i = cur; i < s.size(); ++i) {
		int row = s[i].first;
		int col = s[i].second;

		board[row][col] = 'O';
		DFS(n, s, t, i + 1, level + 1);
		board[row][col] = 'X';
	}
	return;
}

string solution(int n, vector<pair<int, int>>& s, vector<pair<int, int>>& t) {
	string answer;

	//먼저 DFS로 공간이 나올 수 있는 중복조합을 구함
	DFS(n, s, t, 0, 0);

	answer = flag == 1 ? "YES" : "NO";
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<pair<int, int>> space;
	vector<pair<int, int>> teacher;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];

			//선생님인 경우
			if (board[i][j] == 'T')
				teacher.push_back({ i,j });
			//빈 공간
			else if (board[i][j] == 'X')
				space.push_back({ i,j });
		}
	}

	//솔루션
	string ret = solution(n, space, teacher);
	cout << ret;
	return 0;
}
