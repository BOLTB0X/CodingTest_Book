#include <iostream>

using namespace std;

// �Ҽ� �Ǻ� �Լ�(2�̻��� �ڿ����� ���Ͽ�)
bool is_PrimeNumber(int x) {
    // 2���� x�� �����ٱ����� ��� ���� Ȯ���ϸ�
    for (int i = 2; i <= (int)sqrt(x); i++) {
        // x�� �ش� ���� ����������ٸ�
        if (x % i == 0) {
            return false; // �Ҽ��� �ƴ�
        }
    }
    return true; // �Ҽ���
}

int main(void) {
    cout << is_PrimeNumber(4) << '\n';
    cout << is_PrimeNumber(7) << '\n';

    return 0;
}