#include <iostream>
#include <string>
using namespace std;

string str;

int main(void) {
    cin >> str;

    long long  result = str[0] - '0';
    for (int i = 1; i < str.size(); i++) {
        // �� �� �߿��� �ϳ��� '0' Ȥ�� '1'�� ���, ���ϱ⺸�ٴ� ���ϱ� ����
        int num = str[i] - '0';
        if (num <= 1 || result <= 1) {
            result += num;
        }
        else {
            result *= num;
        }
    }

    cout << result;
}