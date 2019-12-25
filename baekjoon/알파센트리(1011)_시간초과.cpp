#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0);

int main() {
	fastIO();
	int T;
	long long x, y, distance;

	cin >> T;
	while (T--) {
		cin >> x >> y;
		distance = y - x;
		if (x == 0) distance++;

		for (long long i = 1; i < distance; i++) {
			if (distance >= i * i - i + 1 && distance <= i * i + 1) {
				if (distance > i * i) cout << 2 * i << '\n';
				else cout << 2 * i - 1 << '\n';

				break;
			}
		}
	}

	return 0;
}