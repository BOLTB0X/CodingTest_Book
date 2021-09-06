#include <iostream>
using namespace std;

int n;
int arr[501];

void quicksort(int* arr, int start, int end) {
	//원소가 1개인 경우
	if (start >= end)
		return;
	int pivot = start; //피벗은 첫번째 원소
	int left = start + 1;
	int right = end;
	int tmp;
	//포인터가 엇갈릴때까지 
	while (left <= right) {
		//피벗보다 작은 데이터를 찾을 때까지 반복
		while (arr[left] >= arr[pivot]) 
			left++;
		while (right > start && arr[right] <= arr[pivot])
			right--;
		if (left > right) {
			tmp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = tmp;
		}
			
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
		else {
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	quicksort(arr, start, right - 1);
	quicksort(arr, right + 1, end);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quicksort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}