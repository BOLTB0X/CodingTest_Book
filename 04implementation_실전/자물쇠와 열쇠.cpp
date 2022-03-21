#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board; // 편의용

// 시계 방향으로 90도 회전
vector<vector<int>> rotate_90(vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> result(n, vector<int> (m));
    
    // 정방이므로
    for (int i = 0; i < n ;++i) {
        for (int j = 0; j < m; ++j)
            result[i][j] = v[n - 1 - j][i];
    }
    
    return result;
}

// 맞는지 체크
int check(int n) {
    // 3배를 키웠으므로
    for (int i = n; i < n * 2; ++i) {
        for (int j = n; j < n * 2; ++j) {
            // 돌기가 아닐시
            if (board[i][j] != 1)
                return 0; // 거짓
        }
    }
    return 1; // 홈이 없으므로
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    // 0 홈, 1 돌기 
    int m = key.size(); // key 길이
    int n = lock.size(); // 자물쇠 길이
    
    // 자물쇠를 3배를 키워서 만듬 -> m의 최솟값이 3이므로
    board.resize(n * 3, vector<int> (n * 3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            board[i + n][j + n] = lock[i][j];
    }
    
    //이제 key를 시계방향 90도로 4번 회전하면서 맞는 지 체크
    for (int r = 0; r < 4; ++r) {
        key = rotate_90(key); // 회전
        
        // key가 들어가므로 2배
        for (int y = 0; y < n * 2; y++) {
            for (int x = 0; x < n * 2; x++) {
                
                // 자물쇠에 회전한 열쇠를 끼워 넣기
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) 
                        board[y + i][x + j] += key[i][j];
                }
                
                // 맞는 지 체크
                if(check(n) == 1) {
                    answer = true;
                    break;
                }
                
                // 자물쇠에 회전한 열쇠를 끼워 넣은거 빼기
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) 
                        board[y + i][x + j] -= key[i][j];
                }
            }
            // 답이 나왔다면
            if (answer)
                break;
        }
        // 답이 나왔다면
        if (answer)
            break;
    }
    
    // 반환
    return answer;
}
