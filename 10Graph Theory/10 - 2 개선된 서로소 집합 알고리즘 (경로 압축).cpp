#include <iostream>

using namespace std;

// ����� ����(V)�� ����(Union ����)�� ����(E)
// ����� ������ �ִ� 100,000����� ����
int v, e;
int parent[100001]; // �θ� ���̺� �ʱ�ȭ�ϱ�

// Ư�� ���Ұ� ���� ������ ã��
int find_Parent(int x) {
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
	if (x == parent[x])
		return x;

	return parent[x] = find_Parent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ��
void union_Parent(int a, int b) {
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

	// Union ������ ���� ����
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		union_Parent(a, b);
	}

	// �� ���Ұ� ���� ���� ����ϱ�
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i <= v; i++)
		cout << find_Parent(i) << ' ';
	cout << '\n';

	// �θ� ���̺� ���� ����ϱ�
	cout << "�θ� ���̺�: ";
	for (int i = 1; i <= v; i++)
		cout << parent[i] << ' ';
	cout << '\n';

	return 0;
}