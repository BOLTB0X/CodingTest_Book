#include <iostream>
#include <vector>

using namespace std;

//병합
void merge(vector<int>& v, int start, int mid, int end) {
	int* sorted = new int[end - start + 1]; //정렬 용
	int i, j, k;

	i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (v[i] <= v[j])
			sorted[k++] = v[i++];
		else
			sorted[k++] = v[j++];
	}

	if (i > mid)
		while (j <= end) sorted[k++] = v[j++];
	else
		while (i <= mid) sorted[k++] = v[i++];

	for (int i = start, k = 0; i <= end; ++i, ++k)
		v[i] = sorted[k];

	delete[] sorted;
	return;
}

//합병정렬
void merge_Sort(vector<int>& v, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_Sort(v, start, mid);
		merge_Sort(v, mid + 1, end);
		merge(v, start, mid, end);
	}
	return;
}

int solution(int n, int m, int k, vector<int>& numbers) {
	int answer = 0;

	merge_Sort(numbers, 0, n - 1); //오름차순 정렬
	int f_value = numbers[n - 1]; //최댓값
	int s_value = numbers[n - 2]; //2번째 값
	int p_cnt = m;
	while (1) {
		//최대 연속으로 k번 더할 수 있으므로
		for (int i = 0; i < k; ++i) {
			//탈출조건
			if (p_cnt == 0)
				break;
			answer += f_value;
			p_cnt--;
		}
		//탈출 조건
		if (p_cnt == 0)
			break;
		//두번째 값
		answer += s_value;
		p_cnt--;
	}
	return answer;
}

int main(void) {
	int n, m, k;
	vector<int> numbers;

	cin >> n >> m >> k;
	numbers.resize(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	int ret = solution(n, m, k, numbers);
	cout << ret;
	return 0;
}