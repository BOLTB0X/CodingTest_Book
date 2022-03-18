#include <iostream>
#include <algorithm>
#define MS 1000001 // 최대 길이

using namespace std;

long long a[MS];
long long b[MS];

int compare(long long& a, long long& b) {
	return a > b;
}

int main(void) {
	int n, k;
	long long answer = 0; // 답

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	// a 기준이므로
	sort(a, a + n); // 오름
	sort(b, b + n, compare); // 내림

	// a와 b의 길이는 같으므로 b의 큰 값들을 더해줌
	for (int i = 0; i < n; ++i) {
		// k 이하
		if (i < k)
			answer += b[i];
		else
			answer += a[i];
	}

	cout << answer;
	return 0;
}
