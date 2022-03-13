#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //

using namespace std;

string solution(string str) {
	string answer;
	int size = str.length();
	int tot = 0;

	for (int i = 0; i < size; ++i) {
		if ('A' <= str[i] && 'Z' >= str[i])
			answer.push_back(str[i]);
		else
			tot += (str[i] - '0');
	}

	sort(answer.begin(), answer.end()); //오름차순 정렬

	answer += to_string(tot);
	return answer;
}

int main() {
	string st;
	cin >> st;

	string ret = solution(st);
	cout << ret;
	return 0;
}
