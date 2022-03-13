#include <string>
#include <vector>

using namespace std;

int Min(int a, int b) {
    return a < b ? a : b;
}

int solution(string s) {
    int size = s.length(); //길이
    int answer = size;

    //압축이므로 반까지만 확인하면 됌
    for (int i = 1; i <= size / 2; ++i) {
        string tmp = "";
        string spl = s.substr(0, i); //비교할 샘플 문자열
        int cnt = 1; //횟수

        for (int j = i; j < size; j += i) {
            //반복되면
            if (spl == s.substr(j, i))
                cnt++;

            //다르게 될 경우
            else {
                if (cnt >= 2)
                    tmp += to_string(cnt);
                tmp += spl;
                spl = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt >= 2)
            tmp += to_string(cnt);
        tmp += spl;

        //길이가 짧은 것으로 교체
        answer = Min(answer, tmp.length());
    }
    return answer;
}