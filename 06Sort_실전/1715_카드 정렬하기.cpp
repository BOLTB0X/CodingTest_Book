#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<int>& cards) {
	int answer = 0;
	priority_queue<int> pq;

	for (int i = 0; i < n; ++i)
		pq.push(-cards[i]);

	while (pq.size() != 1) {
		int fir = -pq.top();
		pq.pop();
		int sec = -pq.top();
		pq.pop();

		answer += fir;
		answer += sec;
		pq.push(-(fir + sec));
	}

	return answer;
}

int main(void) {
	int n;
	vector<int> cards;

	cin >> n;
	cards.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> cards[i];

	int ret = solution(n, cards);
	cout << ret;
	return 0;
}