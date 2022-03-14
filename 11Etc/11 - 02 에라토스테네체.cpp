#include <iostream>
#include <cstring>

using namespace std;

bool prime[1000000] = { true, };

//�����佺�׳�ü
void eratos(void) {
    prime[0] = prime[1] = false; //�Ҽ� X
    
    for (int i = 2; i * i < 1000000; ++i) {
        //�̹� ������ �Ÿ�
        if (!prime[i])
            continue;

        for (int j = i + i; j < 1000000; j += i)
            prime[j] = false;
    }

    return;
}

int main(void) {
    memset(prime, true, 1000000);
    eratos();
    cout << prime[7] << '\n'; // 1
    cout << prime[4] << '\n'; // 0
    cout << prime[31] << '\n'; // 1
    cout << prime[1] << '\n'; // 0
    cout << prime[23243] << '\n'; //0
    return 0;
}