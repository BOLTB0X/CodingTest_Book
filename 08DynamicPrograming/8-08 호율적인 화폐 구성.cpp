#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
void solution (int n, int m, vector<int> arr) {
    // �� �� ���� ����� �����ϱ� ���� DP ���̺� �ʱ�ȭ
    vector<int> d(m + 1, 10001);

    // ���̳��� ���α׷���(Dynamic Programming) ����(���Ҿ�)
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= m; j++) {
            // (i - k)���� ����� ����� �����ϴ� ���
            if (d[j - arr[i]] != 10001) {
                d[j] = min(d[j], d[j - arr[i]] + 1);
            }
        }
    }

    // ���� ��� ���
    if (d[m] == 10001) { // ���������� M���� ����� ����� ���� ���
        cout << -1 << '\n';
    }
    else {
        cout << d[m] << '\n';
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        arr.push_back(value);
    }
    solution(n, m, arr);
    return 0;
}
