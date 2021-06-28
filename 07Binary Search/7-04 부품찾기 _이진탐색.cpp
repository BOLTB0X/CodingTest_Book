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
        // ã�� ��� �߰��� �ε��� ��ȯ
        if (arr[mid] == target)
            return mid;
        // �߰����� ������ ã���� �ϴ� ���� ���� ��� ���� Ȯ��
        else if (arr[mid] > target)
            end = mid - 1;
        // �߰����� ������ ã���� �ϴ� ���� ū ��� ������ Ȯ��
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
		int goal = client[i]; //�մ��� �ֹ� ��ǰ
		int result = BinarySearch(store, goal, 0, n - 1); //����Ž������ ������ �ֳ� Ȯ��
		if (result == -1)
			cout << "no" << ' ';
		else
			cout << "yes" << ' ';
	}
	return 0;
}