#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<int> data;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		data.push_back(value);
	}
	sort(data.begin(), data.end());
	int answer = data[n - 1 / 2];
	cout << answer << endl;
}