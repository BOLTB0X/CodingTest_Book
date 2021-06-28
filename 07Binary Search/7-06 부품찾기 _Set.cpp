#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
set<int> store;
vector<int> client;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        store.insert(x);
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
        if (store.find(client[i]) == store.end()) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}