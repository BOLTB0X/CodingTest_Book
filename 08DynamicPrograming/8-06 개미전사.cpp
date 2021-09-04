#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int solution(int arr[], int n) {
	int answer;
	int dp[101] = { 0, };

	dp[1] = arr[1];
	dp[2] = max(arr[1], arr[2]);
	//보텀업
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	}
	answer = dp[n];
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int arr[101];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int ret = solution(arr, n);
	cout << ret << '\n';
	return 0;
}
