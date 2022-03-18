#include <iostream>
#include <algorithm> // sort

using namespace std;

struct Student{
	string name;
	int kor, eng, mat;

	bool operator < (const Student& s) const {
		if (kor == s.kor) {
			if (eng == s.eng) {
				if (mat == s.mat)
					return name < s.name;
				return mat > s.mat;
			}
			return  eng < s.eng;		
		}
		return kor > s.kor;
	}
};

Student arr[100001];
int idx = 0;


int main(void) {
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string n;
		int k, e, m;

		cin >> n >> k >> e >> m;
		arr[idx++] = { n,k,e,m };
	}

	sort(arr, arr + idx); // 정렬

	// 출력
	for (int i = 0; i < n; ++i)
		cout << arr[i].name << '\n';

	return 0;
}