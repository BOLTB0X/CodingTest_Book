#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int i = 0, one_cnt = 0, zero_cnt = 0;
	char nums[1000000];

	while (1) { //���ڿ� �Է� ����
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
			// �������� 0�� ������ �׳� ���� �ɷ� �Ѿ��, 0 �ڿ� 1�� ���´ٸ� zero ���� ���� �� �������� �Ѿ
		}
		else {
			while (nums[j + 1] == '1')
				j++;
			one_cnt += 1;
			j++;
			// �������� 1�� ������ �׳� ���� �ɷ� �Ѿ��, 1 �ڿ� 0�� ���´ٸ� one ���� ���� �� �������� �Ѿ
		}

		if (nums[j] == '\n')
			break;
	}

	int min = (zero_cnt < one_cnt) ? zero_cnt : one_cnt;
	printf("%d", min);
	//zero�� one �� �� ���� ���� ���
}