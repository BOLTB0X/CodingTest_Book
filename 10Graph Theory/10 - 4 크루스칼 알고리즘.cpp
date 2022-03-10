#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����� ����(V)�� ����(Union ����)�� ����(E)
// ����� ������ �ִ� 100,000����� ����
int v, e;
int parent[100001]; // �θ� ���̺� �ʱ�ȭ
// ��� ������ ���� ����Ʈ��, ���� ����� ���� ����
vector<pair<int, pair<int, int> > > edges;
int result = 0;

// Ư�� ���Ұ� ���� ������ ã��
int find_Parent(int x) {
    // ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
    if (x == parent[x]) 
        return x;
    return parent[x] = find_Parent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ��
void unionParent(int a, int b) {
    a = find_Parent(a);
    b = find_Parent(b);

    if (a < b) 
        parent[b] = a;
    else 
        parent[a] = b;

    return;
}

int main(void) {
    cin >> v >> e;

    // �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
    for (int i = 1; i <= v; i++) 
        parent[i] = i;

    // ��� ������ ���� ������ �Է� �ޱ�
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        // �������� �����ϱ� ���ؼ� Ʃ���� ù ��° ���Ҹ� ������� ����
        edges.push_back({ cost, {a, b} });
    }

    // ������ �������� ����
    sort(edges.begin(), edges.end());

    // ������ �ϳ��� Ȯ���ϸ�
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        // ����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ����
        if (find_Parent(a) != find_Parent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }

    cout << result << '\n';
    return 0;
}