#include <iostream>
#include <string>
using namespace std;

int main() {
	string st;
	int tot = 0;

	cin >> st;
	for (int i = 0; i < st.length() / 2; i++) {
		int num = st[i] - '0';
		tot += num;
	}
	for (int i = st.length() / 2; i < st.length(); i++) {
		int num = st[i] - '0';
		tot -= num;
	}
	if (tot == 0) cout << "LUCKY" << endl;
	else cout << "READY" << endl;
}