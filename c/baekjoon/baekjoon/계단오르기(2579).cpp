#include <iostream>
#include <algorithm>
using namespace std;

int n, stair[301], cache[301];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> stair[i];

	cache[0] = stair[0];
	cache[1] = stair[0] + stair[1];
	cache[2] = max(cache[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) cache[i] = max(stair[i] + stair[i - 1] + cache[i - 3], stair[i] + cache[i - 2]);

	cout << cache[n - 1];

	return 0;
}