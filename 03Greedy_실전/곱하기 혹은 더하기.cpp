#include <iostream>
#include <string>

using namespace std;

long long solution(string str) {
    long long answer = 0;

    for (char& number : str) {
        int n = number - '0';

        if (n <= 1 || answer <= 1)
            answer += n;
        else
            answer *= n;
    }

    return answer;
}

int main(void) {
    string str;
    cin >> str;
   
    long long ret = solution(str);
    cout << ret;

    return 0;
}
