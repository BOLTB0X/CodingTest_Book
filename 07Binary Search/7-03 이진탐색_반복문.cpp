#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, target;
vector<int> arr;

// ���� Ž�� �ҽ��ڵ� ����(�ݺ���)
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
    cin >> n >> target;
    // ��ü ���� �Է� �ޱ� 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // ���� Ž�� ���� ��� ��� 
    int result = BinarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "���Ұ� �������� �ʽ��ϴ�." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}