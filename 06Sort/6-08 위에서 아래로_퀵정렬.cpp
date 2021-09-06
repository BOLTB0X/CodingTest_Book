#include <iostream>
using namespace std;

int n;
int arr[501];

void quicksort(int* arr, int start, int end) {
	//���Ұ� 1���� ���
	if (start >= end)
		return;
	int pivot = start; //�ǹ��� ù��° ����
	int left = start + 1;
	int right = end;
	int tmp;
	//�����Ͱ� ������������ 
	while (left <= right) {
		//�ǹ����� ���� �����͸� ã�� ������ �ݺ�
		while (arr[left] >= arr[pivot]) 
			left++;
		while (right > start && arr[right] <= arr[pivot])
			right--;
		if (left > right) {
			tmp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = tmp;
		}
			
		// �������� �ʾҴٸ� ���� �����Ϳ� ū �����͸� ��ü
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