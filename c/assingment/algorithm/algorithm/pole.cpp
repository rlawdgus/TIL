#include <fstream>
using namespace std;

long long board[21][21][21];

long long pole(int n, int l, int r) {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				board[i][j][k] = board[i - 1][j][k] * (i - 2) + board[i - 1][j - 1][k] + board[i - 1][j][k - 1];
			}
		}
	}

	return board[n][l][r];
}

int main() {
	ifstream inp("pole.inp");
	ofstream out("pole.out");

	int T, n, l, r;

	inp >> T;
	while (T--) {
		inp >> n >> l >> r;

		if (n == 1) {
			if (l == 1 && r == 1) out << "1\n";
			else out << "0\n";
		}
		else {
			if (l == 1 && r == 1) out << "0\n";
			else if (l + r >= n + 2) out << "0\n";
			else {
				for (int i = 1; i <= n; i++) {
					board[i][i][1] = 1;
					board[i][1][i] = 1;
				}

				if (board[n][l][r] == 1) out << "1\n";
				else out << pole(n, l, r) << '\n';
			}
		}
	}

	inp.close();
	out.close();
	return 0;
}