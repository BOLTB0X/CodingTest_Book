#include <iostream>
#include <string>

using namespace std;

long long solution(string numbers) {
	long long answer = 0;

	// 문자열 차례로 확인
	for (char& number : numbers) {
		// 더하기
		if (number - '0' <= 1 || answer <= 1)
			answer += (number - '0');

		// 곱하기
		else
			answer *= (number - '0');
	}

	return answer;
}

int main(void) {
	string numbers;

	cin >> numbers;

	long long ret = solution(numbers);
	cout << ret;

	return 0;
}
