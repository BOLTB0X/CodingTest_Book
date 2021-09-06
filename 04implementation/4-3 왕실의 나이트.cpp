#include <iostream>
#include <string>
using namespace std;

const int dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dc[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

bool is_range(int row, int col) {
	if (row < 1 || col < 1 || row > 8 || col > 8)
		return false;
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input_str;
	//문자형+정수
	cin >> input_str;

	int row = input_str[1] - '0';
	int col = input_str[0] - 'a' + 1;

	int result = 0;
	for (int i = 0; i < 8; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (is_range(nr, nc)) {
			result++;
		}
	}
	cout << result << '\n';
	return 0;
}
