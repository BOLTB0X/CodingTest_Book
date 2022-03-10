#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
#define MS 30001 //최대 길이

using namespace std;

vector<pair<int, int> > graph[MS]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
vector<int> dist; // 최단 거리 테이블 만들기

int Max(int a, int b) {
    return a > b ? a : b;
}

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
  
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) { // 큐가 비어있지 않다면
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int cost = -pq.top().first; // 현재 노드까지의 비용 
        int now = pq.top().second; // 현재 노드
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
                pq.push(make_pair(-ncost, graph[now][i].first));
            }
        }
    }
}

pair<int, int> solution(int n, int m, int start) {
    pair<int, int> answer;
    dist.resize(MS, INF); //거리테이블 초기화

    dijkstra(start); //다익스트라 
                     
                   
    int cnt = 0;
    // 도달할 수 있는 노드 중에서, 가장 멀리 있는 노드와의 최단 거리
    int max_dist = 0;
    for (int i = 1; i <= n; i++) {
        // 도달할 수 있는 노드인 경우
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