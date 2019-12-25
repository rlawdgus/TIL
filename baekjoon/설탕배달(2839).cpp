#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;

	if (N % 5) {
		for (; N >= 0; N -= 3) {
			if (N % 5 == 0) { cnt += N / 5; break; }
			else if (N % 5 == 3) { cnt += N / 5 + 1; break; }
			else cnt++;

			if (N < 3) cnt = -1;
		}

		cout << cnt;
	}
	else cout << N / 5;

	return 0;
}