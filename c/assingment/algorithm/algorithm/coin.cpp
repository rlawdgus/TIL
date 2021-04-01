#include <fstream>
#define MAX 101
using namespace std;

bool board[MAX][MAX][MAX];

void coin_game() {
	for (int i = 2, j = 1; i < MAX; i++, j++) {
		if (j != 4) {
			board[0][0][i] = true;
			board[0][i][0] = true;
			board[i][0][0] = true;
		}
		else j = 0;
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				if ((i == 0 && j == 0) || (j == 0 && k == 0) || (k == 0 && i == 0)) continue;

				if (i > 0 && !board[i - 1][j][k]) board[i][j][k] = true;
				else if (i > 1 && !board[i - 2][j][k]) board[i][j][k] = true;
				else if (i > 2 && !board[i - 3][j][k]) board[i][j][k] = true;
				else if (j > 0 && !board[i][j - 1][k]) board[i][j][k] = true;
				else if (j > 1 && !board[i][j - 2][k]) board[i][j][k] = true;
				else if (j > 2 && !board[i][j - 3][k]) board[i][j][k] = true;
				else if (k > 0 && !board[i][j][k - 1]) board[i][j][k] = true;
				else if (k > 1 && !board[i][j][k - 2]) board[i][j][k] = true;
				else if (k > 2 && !board[i][j][k - 3]) board[i][j][k] = true;
			}
		}
	}
}

int main() {
	ifstream inp("coin.inp");
	ofstream out("coin.out");

	int n, a, b, c, tmp;
	coin_game();

	inp >> n;
	while (n--) {
		inp >> a >> b >> c;
		tmp = board[a][b][c] ? 1 : -1;
		out << '(' << a << ' ' << b << ' ' << c << ')' << " : " << tmp << '\n';
	}

	inp.close();
	out.close();
	return 0;
}