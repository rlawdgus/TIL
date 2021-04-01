#include <iostream>
using namespace std;

long long dp[40];

long long fibonacci(int n) {
	if (n == 0) return 0;
	if (n <= 2) return 1;
	else if (dp[n]) return dp[n];
	else {
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return dp[n];
	}
}

int main() {
	int T, N;

	cin >> T;
	while (T--) {
		cin >> N;

		cout << fibonacci(N - 1) << ' ' << fibonacci(N) << '\n';
	}

	return 0;
}