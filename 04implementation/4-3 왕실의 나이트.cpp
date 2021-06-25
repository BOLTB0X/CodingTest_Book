#include <iostream>
using namespace std;
string inputData;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main(void) {
    cin >> inputData;
    int row = inputData[1] - '0';
    int column = inputData[0] - 'a' + 1;

    int result = 0;
    for (int i = 0; i < 8; i++) {
        int next_Row = row + dx[i];
        int next_Column = column + dy[i];
        if (next_Row >= 1 && next_Row <= 8 && next_Column >= 1 && next_Column <= 8) {
            result += 1;
        }
    }
    cout << result << '\n';
    return 0;
}