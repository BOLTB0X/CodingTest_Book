#include <iostream>

using namespace std;

// 소수 판별 함수(2이상의 자연수에 대하여)
bool is_PrimeNumber(int x) {
    // 2부터 x의 제곱근까지의 모든 수를 확인하며
    for (int i = 2; i <= (int)sqrt(x); i++) {
        // x가 해당 수로 나누어떨어진다면
        if (x % i == 0) {
            return false; // 소수가 아님
        }
    }
    return true; // 소수임
}

int main(void) {
    cout << is_PrimeNumber(4) << '\n';
    cout << is_PrimeNumber(7) << '\n';

    return 0;
}