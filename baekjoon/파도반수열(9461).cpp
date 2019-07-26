#include <iostream>
using namespace std;

long long dp[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 0, };

long long wave(int n) {
	if (n == 0) return 0;
	if (dp[n]) return dp[n];
	else {
		dp[n] = wave(n - 2) + wave(n - 3);
		return dp[n];
	}
}

int main() {
	int T, N;

	cin >> T;
	while (T--) {
		cin >> N;
		cout << wave(N) << '\n';
	}

	return 0;
}