#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	int types[4] = { 500, 100, 50, 10 };

	for (int& type : types) {
		answer += (n / type);
		n %= type;
	}

	return answer;
}
int main(void) {
	int n;
	cin >> n;
	int ret = solution(n);
	cout << ret;
	return 0;
}