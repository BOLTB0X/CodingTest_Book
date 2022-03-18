#include <iostream>
#include <algorithm> // sort

using namespace std;

int arr[2001];
int dp[2001];

int solution(int n) {
	int answer = 0;
	int max_value = 0; // �ִ��� ����

	reverse(arr, arr + n); // �������� ����

	//dp �ʱ�ȭ
	for (int i = 0; i < n; ++i)
		dp[i] = 1;

	//LIS ���ؼ� n�� ���ָ� ��
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	//�ִ� ã��
	for (int i = 0; i < n; ++i) 
		max_value = max(max_value, dp[i]);
	
	answer = n - max_value;
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