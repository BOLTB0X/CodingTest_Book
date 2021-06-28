#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> store;
vector<int> client;

int BinarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 중간점 인덱스 반환
        if (arr[mid] == target)
            return mid;
        // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        else if (arr[mid] > target)
            end = mid - 1;
        // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else
            start = mid + 1;
    }
    return -1;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		store.push_back(value);
	}
	sort(store.begin(), store.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int value;
		cin >> value;
		client.push_back(value);
	}

	for (int i = 0; i < m; i++) {
		int goal = client[i]; //손님의 주문 물품
		int result = BinarySearch(store, goal, 0, n - 1); //이진탐색으로 상점에 있나 확인
		if (result == -1)
			cout << "no" << ' ';
		else
			cout << "yes" << ' ';
	}
	return 0;
}