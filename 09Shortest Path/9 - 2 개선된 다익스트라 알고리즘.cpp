#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9 //최댓값

using namespace std;

struct Heap{
    int dist, node;

    bool operator < (const Heap& h) const {
        return dist > h.dist;
    }
};

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int,int>> graph[100001];
// 최단 거리 테이블 만들기
int dist[100001];

void dijkstra(int start) {
    priority_queue<Heap> pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push({ 0, start });
    dist[start] = 0;
    
    // 큐가 비어있지 않다면
    while (!pq.empty()) {
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int cost = pq.top().dist; // 현재 노드까지의 비용 
        int now = pq.top().node; // 현재 노드
        pq.pop();

        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (dist[now] < cost) 
            continue;

        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int ncost = cost + graph[now][i].second;

            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (ncost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = ncost;
                pq.push({ ncost, graph[now][i].first });
            }
        }
    }

    return;
}

int main(void) {
    cin >> n >> m >> start;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].push_back({ b, c });
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(dist, dist + 100001, INF);

    // 다익스트라 알고리즘을 수행
    dijkstra(start);

    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= n; i++) {
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (dist[i] == INF) 
            cout << "INFINITY" << '\n';
        
        // 도달할 수 있는 경우 거리를 출력
        else 
            cout << dist[i] << '\n';
    }

    return 0;
}
