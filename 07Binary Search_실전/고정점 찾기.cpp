#include <iostream>
#define SIZE 1000001
using namespace std;

int n;
int* nums;

int Binary_search(int* nums, int start, int end) {
	if (start > end) return -1;

	int mid = (start + end) / 2;

	if (nums[start] == mid)
		return mid;

	else if (nums[mid] > mid) // 오른쪽에 있으면
		return Binary_search(nums, start, mid - 1);
	else
		return Binary_search(nums, mid + 1, end);
}

int main(void) {
	cin >> n;
	nums = new int[SIZE]; //동적할당 시작
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int idx = Binary_search(nums, 0, n - 1);

	cout << idx << endl;
	return 0;
}
