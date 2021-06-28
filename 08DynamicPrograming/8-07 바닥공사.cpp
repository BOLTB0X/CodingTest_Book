#include <iostream>
using namespace std;

// DP �ʱ�ȭ
int d[1001];
int n;
int solution(int n) {
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796;
    }
    return d[n];
}
int main(void) {
    // ���� N�� �Է¹ޱ�
    cin >> n;
    cout << solution(n) << '\n';
}