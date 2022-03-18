#include <iostream>
#include <algorithm>

using namespace std;

int arr[500];

int compare(int& a, int& b) {
	return a > b;
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';

	return 0;
}
