#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	
	int count = 0, answer = 0;
	
	cin >> n;
	vector<int> guild;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		guild.push_back(t);
	}
	sort(guild.begin(), guild.end());
	for (int i = 0; i < n; i++) {
		count += 1;
		if (count >= guild[i]) {
			answer += 1;
			count = 0;
		}
	}
	cout << answer;
}