#include <string>
#include <vector>

using namespace std;

// 문자열 쪼개기
int split_String(string str) {
    int idx = 0;
    int size = str.length(); // 길이
    int cnt = 0; // 어차피 균형이 잡혀있어 올바른지만 체크
    
    // 확인 시작
    for (int i = 0; i < size; ++i) {
        if (str[i] == '(') // 열린이면
            cnt++;
        
        else  // 닫음이면
            cnt--;
        
        if (cnt == 0)
            return i; // 인덱스 반환
    }
    
    // 완벽한 문자열
    return -1;
}

// 올바른 지 체크
int is_Correct(string str) {
    int size = str.length(); // 길이
    int cnt = 0; // 갯수
    
     // 확인 시작
    for (int i = 0; i < size; ++i) {
        if (str[i] == '(') // 열린이면
            cnt++;
        
        else { // 닫음이면
            if (cnt == 0)
                return 0; // 인덱스 반환 
            cnt--;
        }
    }
    // 올바른 문자열
    return 1;
}

string solution(string p) {
    string answer = "";
    // 문자열은 p는 균형잡힌 괄호
    
    // 1번 조건
    if (p == "")
        return p;
    
    // 2번 조건
    int idx = split_String(p);
    string u = p.substr(0, idx + 1); // 균형잡힌 괄호 문자열
    string v = p.substr(idx + 1);
    
    // 3번 조건
    // 올바른 문자열인가?
    if (is_Correct(u) == 1)
        return u + solution(v); // 수행한 결과 문자열을 u에 이어 붙인 후 반환
    
    // 4번
    else {
        answer += "("; // 4 - 1 
        answer += solution(v); // 4 - 2
        answer += ")"; // 4 - 3
        
        u = u.substr(1, u.size() - 2); // 4 - 4
        
        // 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        
        // 4 - 5
        answer += u;
    }
    
    return answer;
}
