#include <iostream>
using namespace std;

int arr[2] = { 3, 5 };

int main(void) {
    cout << arr[0] << ' ' << arr[1] << '\n';
    swap(arr[0], arr[1]);
    cout << arr[0] << ' ' << arr[1] << '\n';
}