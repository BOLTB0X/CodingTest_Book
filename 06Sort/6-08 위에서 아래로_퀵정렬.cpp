#include <iostream>
using namespace std;

int n;
int arr[501];

void quick_Sort(int* arr, int start, int end) {
	// 탈출 조건
	if (start >= end)
		return;

	int pivot = start;
	int i = start + 1, j = end;

	while (i <= j) {
		// 피벗 보다 큰 값을 만날때까지 이동
		while (arr[i] >= arr[pivot])
			i++;
		while (j > start && arr[j] <= arr[pivot])
			j--;

		// 엇갈렸다면
		if (i > j)
			swap(arr[j], arr[pivot]);
		else
			swap(arr[i], arr[j]);

		quick_Sort(arr, start, j - 1);
		quick_Sort(arr, j + 1, end);
	}

	return;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	quick_Sort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) 
		cout << arr[i] << ' ';
	
	return 0;
}
