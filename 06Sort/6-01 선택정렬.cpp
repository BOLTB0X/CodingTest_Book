#include <iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

void swap(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
}

int main(void) {
    for (int i = 0; i < n; i++) {
        int min_idx = i; //최소값을 i로 설정
        for (int j = i; j < n; j++) {
            if (arr[min_idx] > arr[j]) { //더 작은 값을 만나면
                min_idx = j; 
            }
        }
        swap(arr[i], arr[min_idx]); //교체
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}