#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 제거 함수
vector<vector<int>> remove_answer(vector<vector<int>>& answer, int x, int y, int a) {
    // 임시
    vector<vector<int>> tmp;

    // 탐색
    for (vector<int>& ans : answer) {
        // 제거할 타겟이 있다면
        if (ans[0] == x && ans[1] == y && ans[2] == a)
            continue;

        // 삽입
        tmp.push_back(ans);
    }

    return tmp;
}

//가능한지 체크
int is_possible(vector<vector<int>>& answer) {
    for (vector<int>& ans : answer) {
        int x = ans[0];
        int y = ans[1];
        int a = ans[2]; // 구조물 0 -> 기둥, 1 -> 보

        // 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
        // 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.

        if (a == 0) {
            int flag = 0; // 체크용

            //바닥인지
            if (y == 0)
                flag = 1;
            // '보의 한 쪽 끝 부분 위' 혹은 '다른 기둥 위'라면 정상
            for (vector<int>& an : answer) {
                // 끝 쪽
                if (x - 1 == an[0] && y == an[1] && 1 == an[2])
                    flag = 1;
                // 끝 쪽
                if (x == an[0] && y == an[1] && 1 == an[2])
                    flag = 1;
                // 다른 기둥 위
                if (x == an[0] && y - 1 == an[1] && 0 == an[2])
                    flag = 1;
            }

            if (flag == 0)
                return 0;
        }

        else if (a == 1) {
            int flag = 0; // 체크용
            int l = 0;
            int r = 0;

            // '한쪽 끝부분이 기둥 위' 혹은 '양쪽 끝부분이 다른 보와 동시에 연결'이라면 정상
            for (vector<int>& an : answer) {
                // 끝 쪽
                if (x == an[0] && y - 1 == an[1] && 0 == an[2])
                    flag = 1;

                // 끝 쪽
                if (x  + 1 == an[0] && y - 1 == an[1] && 0 == an[2])
                    flag = 1;

                // 왼 쪽
                if (x - 1 == an[0] && y == an[1] && 1 == an[2])
                    l = 1;
                
                // 오른 쪽
                if (x + 1 == an[0] && y == an[1] && 1 == an[2])
                    r = 1;
            }
            
            if (l == 1 && r == 1) flag = 1;

            // 거짓 반환 
            if (flag == 0)
                return 0;
        }
    }

    return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    //명령어
    for (vector<int>& frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2]; // 구조물 0 -> 기둥, 1 -> 보
        int b = frame[3]; // 명령어 0 -> 삭제, 1 -> 설치

        // 삭제 명령어 이면
        if (b == 0) {
            answer = remove_answer(answer, x, y, a);

            //삭제 후 괜찮은가?
            if (is_possible(answer) == 0) 
                answer.push_back({ x,y,a }); //다시 설치 
        }

        //설치하는 경우
        if (b == 1) {
            answer.push_back({ x,y,a });
            //설치 후 괜찮은가?
            if (is_possible(answer) == 0)
                answer.pop_back();
        }
    }

    sort(answer.begin(), answer.end()); // 오름차순 정렬
    return answer;
}