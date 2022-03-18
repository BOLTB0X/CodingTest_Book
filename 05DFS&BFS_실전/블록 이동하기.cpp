#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int y1, x1, y2, x2;
} Node;

vector<vector<int>> nboard;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//나아갈 방향 
vector<Node> get_Next(Node cur) {
    vector<Node> next;

    // 4방향 확인
    for (int dir = 0; dir < 4; ++dir) {
        int ny1 = cur.y1 + dy[dir];
        int nx1 = cur.x1 + dx[dir];
        int ny2 = cur.y2 + dy[dir];
        int nx2 = cur.x2 + dx[dir];

        // 보드판이 비어있는 경우
        if (nboard[ny1][nx1] == 0 && nboard[ny2][nx2] == 0)
            next.push_back({ ny1, nx1, ny2, nx2 });
    }

    // 가로에 있을 떄
    int hor[2] = { -1,1 };
    if (cur.y1 == cur.y2) {

        // 위쪽으로 회전하거나, 아래쪽으로 회전
        for (int dir = 0; dir < 2; ++dir) {
            // 위쪽 혹은 아래쪽 두 칸이 모두 비어 있다면
            if (nboard[cur.y1 + hor[dir]][cur.x1] == 0 && nboard[cur.y2 + hor[dir]][cur.x2] == 0) {
                next.push_back({ cur.y1, cur.x1, cur.y1 + hor[dir], cur.x1 });
                next.push_back({ cur.y2, cur.x2, cur.y2 + hor[dir], cur.x2 });
            }
        }
    }
    
    // 세로에 있을 떄
    int ver[2] = { -1,1 };
    if (cur.x1 == cur.x2) {

        // 위쪽으로 회전하거나, 아래쪽으로 회전
        for (int dir = 0; dir < 2; ++dir) {
            // 위쪽 혹은 아래쪽 두 칸이 모두 비어 있다면
            if (nboard[cur.y1][cur.x1 + ver[dir]] == 0 && nboard[cur.y2][cur.x2 + ver[dir]] == 0) {
                next.push_back({ cur.y1, cur.x1, cur.y1, cur.x1 + ver[dir] });
                next.push_back({ cur.y2, cur.x2, cur.y2, cur.x2 + ver[dir] });
            }
        }
    }

    return next;
}

int BFS(int n) {
    vector<Node> visited; // 방문리스트
    queue<pair<Node,int>> que;
    que.push({ {1,1,1,2 }, 0 });
    visited.push_back({ 1,1,1,2 });

    // 큐가 비어질때까지
    while (!que.empty()) {
        Node cur = que.front().first;
        int dist = que.front().second;
        que.pop();

        // 도달한 경우
        if ((cur.y1 == n && cur.x1 == n) || (cur.y2 == n && cur.x2 == n))
            return dist;

        // 현재 위치에서 이동할 수 있는 위치
        vector<Node> next = get_Next(cur);

        for (Node& ne : next) {
            int flag = 1;
            // 재방문인지 확인
            for (Node& v : visited) {
                //재방문이면
                if (ne.y1 == v.y1 && ne.x1 == v.x1 && ne.y2 == v.y2 && ne.x2 == v.x2) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                que.push({ ne, dist + 1 });
                visited.push_back(ne);
            }
        }
    }
    return 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size(); // 길이
    
    // 보드의 외곽에 벽을 두는 형태로 변환
    nboard.resize(n + 2, vector<int>(n + 2, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            nboard[i + 1][j + 1] = board[i][j];
    }
    //너비우선 이용
    answer = BFS(n);

    return answer;
}