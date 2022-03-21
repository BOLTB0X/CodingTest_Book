#include <iostream>

using namespace std;

int fears[100001]; // 공포도 배열

void merge(int* v, int start, int mid, int end) {
	int* sorted = new int[end - start + 1];
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

	for (i = start, k = 0; i <= end; ++i, ++k)
		v[i] = sorted[k];

	delete[] sorted;
	return;
}

void merge_Sort(int* v, int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	merge_Sort(v, start, mid);
	merge_Sort(v, mid + 1, end);
	merge(v, start, mid, end);

	return;
}

int solution(int n) {
	// 그리디 알고리즘
	// 모두 참여할 필요 X
	// 공포도 수치만큼 파티원 필요 -> for문으로 탐색하면서 파이원 수랑 공포도랑 같으면 정답 카운트
	int answer = 0;
	int idx = 0;
	int number_of_player = 0;
	// 오름차순 정렬
	merge_Sort(fears, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		number_of_player++; // 카운트

		// 해당 플레이어 공포도 이상이면 ->  커버가능한 모험가이면
		if (number_of_player >= fears[i]) {
			answer++;
			number_of_player = 0;
		}
	}

	// 반환
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> fears[i];


	int ret = solution(n);
	cout << ret;

	return 0;
}
