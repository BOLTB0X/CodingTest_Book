#include <iostream>
#include <vector>
#include <algorithm>
#define Max_Size 100001

using namespace std;

struct Node{
    int cost, a, b;

    bool operator < (Node n) {
        return cost < n.cost;
    }
};

int v, e;
int result = 0;
// 노드의 개수는 최대 100,000
int parent[Max_Size];
vector<Node> edges; // 모든 간선을 담을 리스트와, 최종비용을 담을 변수

int find_Parent(int x) {
    // 루트 노드가 아니라면, 
    // 루트 노드를 찾을 때까지 재귀적 호출
    if (x == parent[x])
        return x;

    return parent[x] = find_Parent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void union_Parent(int a, int b) {
    a = find_Parent(a);
    b = find_Parent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;

    return;
}

void solution(void) {
    // 간선을 비용순으로 정렬
    sort(edges.begin(), edges.end());

    // 간선을 하나씩 확인
    for (int i = 0; i < edges.size(); ++i) {
        int ccost = edges[i].cost;
        int ca = edges[i].a;
        int cb = edges[i].b;

        // 사이클이 발생하지 않는 경우에만 집합 포함
        if (find_Parent(ca) != find_Parent(cb)) {
            union_Parent(ca, cb);
            result += ccost;
        }
    }

    return;
}

int main(void) {
    cin >> v >> e;

    for (int i = 1; i <= v; ++i)
        parent[i] = i;

    // 모든 간선에 대한 정보를 입력 받기
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        // 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
        edges.push_back({ cost, a,b });
    }

    solution();

    cout << result << '\n';
    return 0;
}
