#include <fstream>
using namespace std;

int pathing(int n, int m) {	//��� ���� ���
	int tmp = n;
	if (n < m) { n = m; m = tmp; }	//n�� ũ��

	double result = 1;
	for (int i = n + m, j = m;;) {
		if (i == n && j == 0) break;
		if (i > n) { result *= i; i--; }
		if (j > 0) { result /= j; j--; }
	}

	return (int)result;
}

int waypoint(int n, int m, int k) {	//n�� y��, m�� x��
	int x = k;
	while (1) {
		if (x <= m) break;
		x -= m;
	}

	int y = (k - 1) / m;

	return pathing(x - 1, y) * pathing(m - x, n - y - 1);
}

int main() {
	ifstream inp("path.inp");
	ofstream out("path.out");

	int T, N, M, K;

	inp >> T;
	while (T--) {
		inp >> N >> M >> K;

		if (K == 0) out << pathing(N - 1, M - 1) << '\n';
		else out << waypoint(N, M, K) << '\n';
	}

	inp.close();
	out.close();
	return 0;
}