#include <iostream>
#include <vector>
using namespace std;

int n, m;
int store[1000001];
vector<int> client;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        store[x] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        client.push_back(target);
    }
    // 손님이 확인 요청한 부품 번호를 하나씩 확인
    for (int i = 0; i < m; i++) {
        // 해당 부품이 존재하는지 확인
        if (store[client[i]] == 1) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}