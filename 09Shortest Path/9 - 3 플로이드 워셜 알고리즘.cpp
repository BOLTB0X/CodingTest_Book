#include <iostream>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M)
// 노드의 개수는 최대 500개라고 가정
int n, m;
// 2차원 배열(그래프 표현)를 만들기
int adj[501][501];

int Min(int a, int b) {
    return a < b ? a : b;
}

void init(void) {
    // 최단 거리 테이블을 모두 무한으로 초기화
    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; ++j)
            adj[i][j] = INF;
    }
    
    // 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) 
                adj[a][b] = 0;
        }
    }

    return;
}

void solution(void) {
    // 점화식에 따라 플로이드 워셜 알고리즘을 수행
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                adj[a][b] = Min(adj[a][b], adj[a][k] + adj[k][b]);
            }
        }
    }

    //출력
    // 수행된 결과를 출력
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
            if (adj[a][b] == INF) {
                cout << "INFINITY" << ' ';
            }
            // 도달할 수 있는 경우 거리를 출력
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

    // 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for (int i = 0; i < m; i++) {
        // A에서 B로 가는 비용은 C라고 설정
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    //플로이드 워셜
    solution();

    return 0;
}