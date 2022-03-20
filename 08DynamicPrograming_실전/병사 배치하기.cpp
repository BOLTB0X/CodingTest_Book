#include <iostream>
#include <algorithm> // sort

using namespace std;

int arr[2000]; // 입력받을 배열
int dp[2000]; // dp 테이블

int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = 0;
	int max_len = 1;
	// 가장 긴 증가부분 수열을 가져야 함 -> LIS
	// n - LIS이 열외된 개미 숫자

	reverse(arr, arr + n); // 내림차순 정렬
	
	//LIS 알고리즘
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			// 길이가 크다면
			if (arr[i] > arr[j])
				dp[i] = Max(dp[i], dp[j] + 1);
		}
		max_len = Max(max_len, dp[i]); // 교체
	}
		
	answer = n - max_len;
	return answer;
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n);
	cout << ret;
	return 0;
}
