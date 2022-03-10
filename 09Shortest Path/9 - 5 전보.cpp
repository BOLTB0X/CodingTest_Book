#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����
#define MS 30001 //�ִ� ����

using namespace std;

vector<pair<int, int> > graph[MS]; // �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
vector<int> dist; // �ִ� �Ÿ� ���̺� �����

int Max(int a, int b) {
    return a > b ? a : b;
}

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
  
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) { // ť�� ������� �ʴٸ�
        // ���� �ִ� �Ÿ��� ª�� ��忡 ���� ���� ������
        int cost = -pq.top().first; // ���� �������� ��� 
        int now = pq.top().second; // ���� ���
        pq.pop();

        // ���� ��尡 �̹� ó���� ���� �ִ� ����� ����
        if (dist[now] < cost) 
            continue;

        // ���� ���� ����� �ٸ� ������ ������ Ȯ��
        for (int i = 0; i < graph[now].size(); i++) {
            int ncost = cost + graph[now][i].second;

            // ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
            if (ncost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = ncost;
                pq.push(make_pair(-ncost, graph[now][i].first));
            }
        }
    }
}

pair<int, int> solution(int n, int m, int start) {
    pair<int, int> answer;
    dist.resize(MS, INF); //�Ÿ����̺� �ʱ�ȭ

    dijkstra(start); //���ͽ�Ʈ�� 
                     
                   
    int cnt = 0;
    // ������ �� �ִ� ��� �߿���, ���� �ָ� �ִ� ������ �ִ� �Ÿ�
    int max_dist = 0;
    for (int i = 1; i <= n; i++) {
        // ������ �� �ִ� ����� ���
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
    // ����� ����(N), ������ ����(M), ���� ��� ��ȣ(Start)
    int n, m, start;
    cin >> n >> m >> start;

    // ��� ���� ������ �Է¹ޱ�
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        // X�� ��忡�� Y�� ���� ���� ����� Z��� �ǹ�
        graph[x].push_back({ y, z });
    }

    pair<int, int> ret = solution(n, m, start);
    cout << ret.first << ' ' << ret.second;
    return 0;
}