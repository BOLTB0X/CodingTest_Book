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
    // �մ��� Ȯ�� ��û�� ��ǰ ��ȣ�� �ϳ��� Ȯ��
    for (int i = 0; i < m; i++) {
        // �ش� ��ǰ�� �����ϴ��� Ȯ��
        if (store[client[i]] == 1) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}