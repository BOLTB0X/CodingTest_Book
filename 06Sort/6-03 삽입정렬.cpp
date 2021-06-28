#include <iostream>
using namespace std;

int n = 10;
int arr[10]= { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {
	for (int i = 1; i < n; i++) {
		//i부터 1까지 감소
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
			//자기보다 작은 값을 만나면 그 위치에서 멈춤
			else break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}