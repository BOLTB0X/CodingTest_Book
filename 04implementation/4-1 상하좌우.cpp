#include <iostream>
#include <string>
using namespace std;

int n;
int result[2] = { 0,0 };
//상하 좌우
const int dr[4] = { -1,1,0,0 };
const int dc[4] = { 0,0,-1,1 };
const char move_types[4] = { 'U','D','L','R' };

bool is_range(int row, int col) {
	if (row <1 || col <1 || row > n || col > n)
		return false;
	return true;
}

void simulation(int row, int col, string s) {
	int nr, nc;
	for (int i = 0; i < s.length(); i++) {
		for (int dir = 0; dir < 4; dir++) {
			if (s[i] == move_types[dir]) {
				nr = row + dr[dir];
				nc = col + dc[dir];
			}
		}
		if (is_range(nr, nc)) {
			row = nr;
			col = nc;
		}
	}
	result[0] = row;
	result[1] = col;
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string plans;
	cin >> n;
	cin.ignore(); //버퍼비우기
	getline(cin, plans);
	simulation(1, 1, plans);
	for (int i = 0; i < 2; i++) {
		cout << result[i] << ' ';
	}
	cout << '\n';
	return 0;
}
