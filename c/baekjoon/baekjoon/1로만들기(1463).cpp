#include <iostream>
#include <algorithm>
#define INF 1000001
using namespace std;

int cache[1000001];

int main() {
	int N, tmp, tmp2, tmp3;
	cin >> N;

	cache[2] = 1;
	cache[3] = 1;

	for (int i = 4; i <= N; i++) {
		tmp = tmp2 = tmp3 = INF;

		if (cache[i - 1] != 0) tmp = cache[i - 1] + 1;
		if (i % 3 == 0) tmp2 = cache[i / 3] + 1;
		if (i % 2 == 0) tmp3 = cache[i / 2] + 1;

		cache[i] = min(min(tmp, tmp2), tmp3);
	}
	
	cout << cache[N];

	return 0;
}