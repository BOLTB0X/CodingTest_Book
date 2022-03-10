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

	for (int i = 0; i < size - 1; i++) {
		//두번쨰 원소부터 확인
		//다르다면
		if (str[i] != str[i + 1]) {
			//0으로 변환
			if (str[i + 1] == '1') 
				zero_cnt++;

			//1로 변환
			else 
				one_cnt++;
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
