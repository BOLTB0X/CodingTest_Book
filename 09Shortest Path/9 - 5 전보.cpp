#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000 // 무한을 의미하는 값으로 10억을 설정
#define MS 30001 //최대 길이
#define LL long long

using namespace std;

typedef struct {
    int target, cost;
} Node;

vector<Node> graph[MS]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
vector<int> dist; // 최단 거리 테이블 만들기

//최댓값 반환
int Max(int a, int b) {
    return a > b ? a : b;
}

void dijkstra(int n, int m, int start) {
    priority_queue<pair<int,int>> pq; // 우선순위 큐 선언
    pq.push({ 0,start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cdist = -pq.top().first;
        pq.pop();

        // 이미 방문한 거리라면
        if (dist[cur] < cdist)
            continue;

        for (Node& next : graph[cur]) {
            int ndist = cdist + next.cost;

            if (ndist < dist[next.target]) {
                dist[next.target] = ndist;
                pq.push({ -ndist, next.target });
            }
        }
    }

    return;
}

pair<int, int> solution(int n, int m, int start) {
    pair<int, int> answer;
    int cnt = 0, max_dist = 0;

    dist.resize(n + 1, INF);
    dijkstra(n, m, start); // 다익스트라

    for (int i = 1; i <= n; ++i) {
        if (dist[i] != INF) {
            cnt++;
            max_dist = Max(max_dist, dist[i]);
        }
    }
    
    answer.first = cnt - 1;
    answer.second = max_dist;
    return answer;
}

int main(void) {
    // 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
    int n, m, start;
    cin >> n >> m >> start;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int x, y, z;

        cin >> x >> y >> z;
        // X번 노드에서 Y번 노드로 가는 비용이 Z라는 의미
        graph[x].push_back({ y, z });
    }

    pair<int, int> ret = solution(n, m, start);
    cout << ret.first << ' ' << ret.second;
    return 0;
}
