#include <iostream>
#include <string>
using namespace std;

int main() {
	string nums;
	int zero_cnt = 0; 
	int one_cnt = 0;
	cin >> nums;

	if (nums[0] == '1') {
		zero_cnt += 1;
	}
	else {
		one_cnt += 1;
	}
	for (int i = 0; i<nums.length()-1; i++) {
		if (nums[i] != nums[i + 1]) {
			if (nums[i + 1] == '1') 
				zero_cnt += 1;
			else 
				one_cnt += 1;
		}
	}
	int min_cnt= (one_cnt>zero_cnt) ? zero_cnt : one_cnt;
	cout << min_cnt << endl;
}