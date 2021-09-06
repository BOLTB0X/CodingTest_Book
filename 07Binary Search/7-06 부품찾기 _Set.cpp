#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> store;
int client[1000001];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int* arr, int start, int end) {
	if (start >= end) 
		return; //원소가 1개인 경우
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

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		store.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> client[i];
	}

	//손님이 확인 요청한 부품번호를 하나씩 확인
	for (int i = 0; i < m; i++) {
		if (store.find(client[i]) != store.end())
			cout << "yes" << ' ';
		else
			cout << "no" << ' ';
	}
	cout << '\n';
	return 0;
}
