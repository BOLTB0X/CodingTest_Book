#include <iostream>
#include <algorithm>

using namespace std;

//����
void merge(int* v, int start, int mid, int end) {
	int* sorted = new int[end - start + 1]; //���� ��
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

//�պ�����
void merge_Sort(int* v, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_Sort(v, start, mid);
		merge_Sort(v, mid + 1, end);
		merge(v, start, mid, end);
	}
	return;
}

int main(void) {
	int n, m, k;
	int numbers[1001];
	int answer = 0;
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	merge_Sort(numbers, 0, n - 1); //�������� ����
	int cnt = 0;
	int fir = numbers[n - 1];
	int sec = numbers[n - 2];
	
	cnt = ((m / (k + 1)) * k);
	cnt += (m % (k + 1));

	answer += (cnt * fir);
	answer += ((m - cnt) * sec);

	cout << answer;
	return 0;
}