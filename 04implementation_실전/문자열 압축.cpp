#include <string>
#include <vector>

using namespace std;

int Min(int a, int b) {
    return a < b ? a : b;
}

int solution(string s) {
    int size = s.length(); //����
    int answer = size;

    //�����̹Ƿ� �ݱ����� Ȯ���ϸ� ��
    for (int i = 1; i <= size / 2; ++i) {
        string tmp = "";
        string spl = s.substr(0, i); //���� ���� ���ڿ�
        int cnt = 1; //Ƚ��

        for (int j = i; j < size; j += i) {
            //�ݺ��Ǹ�
            if (spl == s.substr(j, i))
                cnt++;

            //�ٸ��� �� ���
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

        //���̰� ª�� ������ ��ü
        answer = Min(answer, tmp.length());
    }
    return answer;
}