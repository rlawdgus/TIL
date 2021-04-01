#include <iostream>
using namespace std;

int n[10000001];

int main() {
	int N;
	n[0] = 0, n[1] = 1, n[2] = 1;

	cin >> N;
	for (int i = 3; i <= N + 1; i++) {
		n[i] = n[i - 1] + n[i - 2];
		n[i] %= 15746;
	}

	cout << n[N + 1];

	return 0;
}