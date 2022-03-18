#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	int answer = 0;
	cin >> n >> k;

	//1이 될 때까지
	while (n != 1) {
		answer++;

		if (n % k == 0) 
			n /= k;
		else 
			n--;
	}
	
	cout << answer;
	return 0;
}