#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct inf {
	string name;
	int score;
};

bool compare (const inf a, const inf b) {
	return a.score < b.score;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<inf> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		int tmp_score;
		cin >> tmp >> tmp_score;
		arr.push_back({ tmp,tmp_score });
	}
	sort(arr.begin(), arr.end(),compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].name << ' ';
	}
	return 0;
}