#include <iostream>
using namespace std;

int dp[10000] = { 0 };

int fibonacci(int num) {
	if (num == 1 || num == 2) return 1;
	//return fibonacci(num - 1) + fibonacci(num - 2);

	else if (dp[num]) return dp[num];
	
	else {
		dp[num] = fibonacci(num - 1) + fibonacci(num - 2);
		return dp[num];
	}
}

int main() {
	int num;
	while (1) {
		cin >> num;

		if (num == -1) return 0;
		cout << fibonacci(num) << "\n\n";
	}
}