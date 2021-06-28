#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, target;
vector<int> arr;

int BinarySearch(vector<int>& arr, int target, int start, int end) {
    if (start > end) //�� ã�� �ٸ�
        return -1;
    int mid = (start + end) / 2;
    // ã�� ��� �߰��� �ε��� ��ȯ
    if (arr[mid] == target) 
        return mid;
    // �߰����� ������ ã���� �ϴ� ���� ���� ��� ���� Ȯ��
    else if (arr[mid] > target) 
        return BinarySearch(arr, target, start, mid - 1);
    // �߰����� ������ ã���� �ϴ� ���� ū ��� ������ Ȯ��
    else 
        return BinarySearch(arr, target, mid + 1, end);
}

int main(void) {
    // n(������ ����)�� target(ã���� �ϴ� ��)�� �Է¹ޱ� 
    cin >> n >> target;
    // ��ü ���� �Է¹ޱ� 
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