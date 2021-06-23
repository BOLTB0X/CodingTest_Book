#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string st;
	int nums = 0;
	vector<char> answer;
	cin >> st;

	for (int i = 0; i < st.length(); i++) {
		if (isalpha(st[i])) {
			answer.push_back(st[i]);
		}
		else {
			nums += st[i] - '0';
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	if (nums != 0) {
		cout << nums;
	}
	cout << '\n';
}