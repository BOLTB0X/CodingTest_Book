#include <iostream>
#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ����(N), ������ ����(M)
// ����� ������ �ִ� 500����� ����
int n, m;
// 2���� �迭(�׷��� ǥ��)�� �����
int adj[501][501];

int Min(int a, int b) {
    return a < b ? a : b;
}

void init(void) {
    // �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; ++j)
            adj[i][j] = INF;
    }
    
    // �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) 
                adj[a][b] = 0;
        }
    }

    return;
}

void solution(void) {
    // ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                adj[a][b] = Min(adj[a][b], adj[a][k] + adj[k][b]);
            }
        }
    }

    //���
    // ����� ����� ���
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            // ������ �� ���� ���, ����(INFINITY)�̶�� ���
            if (adj[a][b] == INF) {
                cout << "INFINITY" << ' ';
            }
            // ������ �� �ִ� ��� �Ÿ��� ���
            else {
                cout << adj[a][b] << ' ';
            }
        }
        cout << '\n';
    }

    return;
}

int main(void) {
    cin >> n >> m;

    init();

    // �� ������ ���� ������ �Է� �޾�, �� ������ �ʱ�ȭ
    for (int i = 0; i < m; i++) {
        // A���� B�� ���� ����� C��� ����
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    //�÷��̵� ����
    solution();

    return 0;
}