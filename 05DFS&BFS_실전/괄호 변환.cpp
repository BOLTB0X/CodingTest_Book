#include <string>
#include <vector>

using namespace std;

//올바른 괄호인가?
int is_Correct(string s) {
    int cnt = 0;
    //stack<char> st; 균형잡인게 조건이므로 균형만 보면 됌
    for (char& c : s) {
        //오픈이면
        if (c == '(')
            cnt++;
        else {
            //클로즈고 탑이 오픈일경우
            if (cnt == 0)
                return 0;
            cnt--;
        }
    }
    //에초에 문자열이 균형잡혀있음
    //참 반환
    return 1;
}

//특정부분 인덱스 반환
int get_split_idx(string w) {
    int cnt = 0;
    int size = w.length();

    for (int i = 0; i < size; ++i) {
        if (w[i] == '(')
            cnt++;
        else
            cnt--;

        if (cnt == 0)
            return i;
    }
    return -1;
}

string solution(string p) {
    string answer = "";
    string u = "", v = "";

    // 1번
    if (p == "")
        return "";

    // 2번
    int idx = get_split_idx(p);
    u = p.substr(0, idx + 1);
    v = p.substr(idx + 1);

    // 3번
    if (is_Correct(u) == 1)
        answer = u + solution(v);
    // 4번
    else {
        answer += "("; // 4 - 1
        answer += solution(v); // 4 - 2
        answer += ")"; // 4 - 3

        // 4 - 4
        u = u.substr(1, u.size() - 2);

        // 4 - 5
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        answer += u; // 4 - 5
    }

    return answer;
}