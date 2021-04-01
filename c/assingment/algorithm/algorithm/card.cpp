#include <fstream>
#include <algorithm>
using namespace std;

int input[1000];
int board[3][1000];

void select(int size) {
	for (int i = 4; i < size; i++) {
		board[0][i] = input[i] + max(board[1][i - 2], board[2][i - 2]);
		board[1][i] = input[i] + max(board[0][i - 3], max(board[1][i - 3], board[2][i - 3]));
		board[2][i] = input[i] + max(board[0][i - 4], max(board[1][i - 4], board[2][i - 4]));
	}
}

int main() {
	ifstream inp("card.inp");
	ofstream out("card.out");

	int T, n;

	inp >> T;
	while (T--) {
		inp >> n;
		for (int i = 0; i < n; i++) {
			inp >> input[i];
		}

		board[0][0] = board[1][0] = board[2][0] = input[0];
		board[0][1] = board[1][1] = board[2][1] = input[1];

		board[0][2] = -10000;
		board[1][2] = board[2][2] = input[2];

		board[0][3] = input[1] + input[3];
		board[1][3] = input[0] + input[3];
		board[2][3] = -10000;

		select(n);
		out << max(board[0][n - 1], max(board[1][n - 1], board[2][n - 1])) << '\n';
	}

	inp.close();
	out.close();
	return 0;
}