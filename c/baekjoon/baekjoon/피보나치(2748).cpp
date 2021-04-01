#include <iostream>
using namespace std;

long long dp[90] = { 0 };

long long fibonacci(int n) {
	if (n <= 2) return 1;
	else if (dp[n]) return dp[n];
	else {
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return dp[n];
	}
}

int main() {
	int n;

	cin >> n;
	cout << fibonacci(n);

	return 0;
}