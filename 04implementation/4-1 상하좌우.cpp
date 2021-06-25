#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	string plans;
	int x = 1 , y = 1;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	char move_type[4] = { 'U','D','L','R' };

	cin >> n;
	cin.ignore(); // 버퍼 비우기
	getline(cin, plans);
	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		int nx = -1, ny = -1;
		for (int j = 0; j < 4; j++) {
			if (plan == move_type[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
			if (nx < 1 || ny < 1 || nx > n || ny > n) 
				continue;
			x = nx;
			y = ny;
		}
	}
	cout << x << ' ' << y << endl;
	return 0;
}