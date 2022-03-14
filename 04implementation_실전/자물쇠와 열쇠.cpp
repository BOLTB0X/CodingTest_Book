#include <string>
#include <vector>

using namespace std;

// 2차원 리스트 90도 회전하기
vector<vector<int>> rotate_90(vector<vector<int>>& v) {
    int n = v.size(); // 행 길이 계산
    int m = v[0].size(); // 열 길이 계산

    vector<vector<int> > result(n, vector<int>(m)); // 결과 리스트
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = v[n - 1 - j][i];
        }
    }
    return result;
}

// 자물쇠의 중간 부분이 모두 1인지 확인
int check(vector<vector<int>>& board) {
    int n = board.size() / 3;

    //검사 시작
    for (int i = n; i < n * 2; i++) {
        for (int j = n; j < n * 2; j++) {
            //0으로 하면 안될수도 있음
            if (board[i][j] != 1) 
                return 0;
        }
    }

    return 1;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    int n = lock.size();
    int m = key.size();

    // 자물쇠의 크기를 기존의 3배로 변환 -> 각 범위의 최솟값이 3
    vector<vector<int> > board(n * 3, vector<int>(n * 3));

    // 새로운 자물쇠의 중앙 부분에 기존의 자물쇠 넣기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            board[i + n][j + n] = lock[i][j];
    }

    // 90도씩 회전
    for (int r = 0; r < 4; ++r) {
        key = rotate_90(key); // 열쇠 회전
        for (int y = 0; y < n * 2; y++) {
            for (int x = 0; x < n * 2; x++) {

                // 자물쇠에 회전한 열쇠를 끼워 넣기
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) 
                        board[y + i][x + j] += key[i][j];
                }

                // 정확히 들어 맞는지 검사
                if (check(board) == 1) 
                    return true;

                // 자물쇠에서 열쇠를 다시 빼기
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) 
                        board[y + i][x + j] -= key[i][j];
                }
            }
        }
    }

    return false;
}