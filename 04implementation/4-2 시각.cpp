#include <iostream>
#include <string>
using namespace std;

int h, cnt;

int main(void) {
    // H를 입력받기 
    cin >> h;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                // 매 시각 안에 '3'이 포함되어 있다면 카운트 증가
                if (i % 10 == 3 || j / 10 == 3 || j % 10 == 3 || k / 10 == 3 || k % 10 == 3)
                    cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}