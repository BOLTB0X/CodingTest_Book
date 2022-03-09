#include <iostream>
#include <vector>

using namespace std;

int get_Min_value(int m, vector<int>& cards) {
	int ret = cards[0];

	for (int i = 1; i < m; ++i) {
		if (ret > cards[i])
			ret = cards[i];
	}

	return ret;
}

int solution(int n, int m, vector<vector<int>>& cards) {
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		int min_value = get_Min_value(m, cards[i]);
		if (answer < min_value)
			answer = min_value;
	}

	return answer;
}
int main(void) {
	int n, m;
	vector<vector<int>> cards;

	cin >> n >> m;
	cards.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> cards[i][j];
	}

	int ret = solution(n, m, cards);
	cout << ret;
	return 0;
}