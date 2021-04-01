#include <iostream>
using namespace std;

int main() {
	int T, H, W, N, tmp;
	cin >> T;

	while (T--) {
		cin >> H >> W >> N;
		
		N--;
		tmp = N / H + 1;
		if (tmp < 10) cout << N % H + 1 << "0" << tmp << '\n';
		else cout << N % H + 1 << tmp << '\n';
	}

	return 0;
 }