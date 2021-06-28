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
    // �մ��� Ȯ�� ��û�� ��ǰ ��ȣ�� �ϳ��� Ȯ��
    for (int i = 0; i < m; i++) {
        // �ش� ��ǰ�� �����ϴ��� Ȯ��
        if (store.find(client[i]) == store.end()) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}