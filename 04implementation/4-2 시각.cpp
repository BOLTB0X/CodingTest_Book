#include <iostream>
#include <string>
using namespace std;

int h, cnt;

int main(void) {
    // H�� �Է¹ޱ� 
    cin >> h;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                // �� �ð� �ȿ� '3'�� ���ԵǾ� �ִٸ� ī��Ʈ ����
                if (i % 10 == 3 || j / 10 == 3 || j % 10 == 3 || k / 10 == 3 || k % 10 == 3)
                    cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}