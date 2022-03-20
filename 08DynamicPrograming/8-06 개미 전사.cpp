#include <iostream>

using namespace std;

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n;

	cin >> n;
	int* arr = new int[n + 1];
	int* dp = new int[n + 1];
	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		dp[i] = 0;
	}

	// 보텀업 방식
	// 왼쪽부터 차례로 나아간다 생각하면
	// 1번 -> 1, 2번에 왔을 때 2와 1중 큰 것
	// 3부턴 dp테이블 참고하여 한칸 떨어진 것+ 현제와 바로 한칸 dp테이블
	dp[1] = arr[1];
	dp[2] = Max(arr[1], arr[2]);

	for (int i = 3; i <= n; ++i) 
		dp[i] = Max(dp[i - 1], dp[i - 2] + arr[i]);
	
	cout << dp[n];
	free(arr);
	free(dp);
	return 0;
}
