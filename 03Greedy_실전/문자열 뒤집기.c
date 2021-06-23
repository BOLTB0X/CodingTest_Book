#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int i = 0, one_cnt = 0, zero_cnt = 0;
	char nums[1000000];

	while (1) { //문자열 입력 구간
		scanf("%c", &nums[i]);

		if (nums[i++] == '\n')
			break;
	}
	int j = 0;
	while (1) {
		if (nums[j] == '0') {
			while (nums[j + 1] == '0')
				j++;
			zero_cnt += 1;
			j++;
			// 연속으로 0이 나오면 그냥 다음 걸로 넘어가고, 0 뒤에 1이 나온다면 zero 값을 더한 뒤 다음으로 넘어감
		}
		else {
			while (nums[j + 1] == '1')
				j++;
			one_cnt += 1;
			j++;
			// 연속으로 1이 나오면 그냥 다음 걸로 넘어가고, 1 뒤에 0이 나온다면 one 값을 더한 뒤 다음으로 넘어감
		}

		if (nums[j] == '\n')
			break;
	}

	int min = (zero_cnt < one_cnt) ? zero_cnt : one_cnt;
	printf("%d", min);
	//zero와 one 값 중 작은 것을 출력
}