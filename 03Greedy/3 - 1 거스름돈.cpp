#include <iostream>

using namespace std;

int main(void) {
	int n;
	int coins[4] = { 500, 100, 50, 10 };

	cin >> n;

	int cnt = 0;
	for (int& coin : coins) {
		cnt += (n / coin);
		n %= coin;
	}

	cout << cnt;
	return 0;
}
