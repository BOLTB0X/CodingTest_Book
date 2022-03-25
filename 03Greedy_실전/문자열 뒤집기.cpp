#include <iostream>
#include <string>

using namespace std;

int solution(string str) {
	int answer = 0;
	int size = str.length();
	int zero_cnt = 0; 
	int one_cnt = 0;

	if (str[0] == '1') 
		zero_cnt++;
	else 
		one_cnt++;

	// 연속된 수를 바꾸는 것이므로
	// 달라지는 부분마다 0,1인지 체크
	for (int i = 0; i < size - 1; ++i) {
		if (str[i] != str[i + 1]) {
			if (str[i + 1] == '0')
				one_cnt++;
			else if (str[i + 1] == '1')
				zero_cnt++;
		}
	}

	answer = (one_cnt > zero_cnt) ? zero_cnt : one_cnt;
	return answer;
}

int main(void) {
	string nums;
	cin >> nums;

	int ret = solution(nums);
	cout << ret;

	return 0;
}
