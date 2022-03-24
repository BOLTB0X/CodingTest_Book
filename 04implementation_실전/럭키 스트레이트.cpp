#include <iostream>
#include <string>

using namespace std;

string solution(string str) {
	string answer = "READY";
	int tot = 0;
	int size = str.length();

	for (int i = 0; i < size / 2; ++i)
		tot += (int)(str[i] - '0');
	
	for (int i = size / 2; i < size; ++i)
		tot -= (int)(str[i] - '0');

	if (tot == 0)
		answer = "LUCKY";

	return answer;
}

int main() {
	string str;

	cin >> str;

	string ret = solution(str);
	cout << ret;
	
	return 0;
}
