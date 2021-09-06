#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int* arr, int start, int end) {
	if (start >= end) return; //원소가 1개인 경우
	int pivot = start; //피벗은 첫 번째 원소
	int left = start + 1;
	int right = end;
	while (left <= right) {
		//피벗보다 큰 데이터를 찾을 때까지 반복
		while (left <= end && arr[left] <= arr[pivot]) 
			left++;
		// 피벗보다 작은 데이터를 찾을 때까지 반복
		while (right > start && arr[right] >= arr[pivot]) 
			right--;
		// 엇갈렸다면 작은 데이터와 피벗을 교체
		if (left > right) 
			swap(arr[pivot], arr[right]);
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
		else 
			swap(arr[left], arr[right]);
	}
	// 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
	quicksort(arr, start, right - 1);
	quicksort(arr, right + 1, end);
}

bool binarysearch(int* arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target)
			return true;
		if (arr[mid] > target)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//퀵정렬
	quicksort(arr,0,n-1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		bool check = binarysearch(arr, target, 0, n - 1);
		if (check) cout << "yes" << ' ';
		else cout << "no" << ' ';
	}
	cout << '\n';
	return 0;
}
