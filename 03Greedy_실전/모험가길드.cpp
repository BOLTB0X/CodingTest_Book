#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int start, int mid, int end) {
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

void merge_Sort(vector<int>& v, int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	merge_Sort(v, start, mid);
	merge_Sort(v, mid + 1, end);
	merge(v, start, mid, end);

	return;
}

int solution(int n, vector<int>& guild) {
	int answer = 0;
	int cnt = 0;

	//오름차순 정렬
	merge_Sort(guild, 0, n - 1);

	//그리디 알고리즘
	//모든 모험가를 넣을 필요 X
	for (int& player : guild) {
		cnt++; //인원수 카운트

		//해당 플레이어 공포도 이상이면 ->  커버가능한 모험가이면
		if (cnt >= player) {
			answer++;
			cnt = 0;
		}
	}
	return answer;
}

int main() {
	int n;
	vector<int> guild;
	
	cin >> n;
	guild.resize(n, 0);

	for (int i = 0; i < n; i++) 
		cin >> guild[i];
	
	int ret = solution(n, guild);
	cout << ret;

	return 0;
}
