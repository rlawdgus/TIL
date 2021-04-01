#include <iostream>
using namespace std;

int apartment[15][15];

int main() {
	int T, k, n;
	for (int i = 1; i < 15; i++) apartment[0][i] = i;
	for (int i = 1; i < 15; i++) apartment[i][1] = 1;

	for (int i = 1; i < 15; i++) {
		for (int j = 2; j < 15; j++) {
			apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
		}
	}

	cin >> T;
	while (T--) {
		cin >> k >> n;

		cout << apartment[k][n] << '\n';
	}

	return 0;
}