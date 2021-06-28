#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[100] = {0};
int arr[1001];

int solution(int n,int* arr) {
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; i++) {
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);
	}
	return d[n - 1];
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << solution(n, arr) << '\n';
}