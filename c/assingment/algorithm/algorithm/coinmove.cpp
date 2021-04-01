#include <fstream>
using namespace std;

bool board[1000001][8];

void set_feild(int P, int K, int i, int j) {
	if (i - j != 0 && (i - j) % P == 0) { board[i][j] = false; return; }
	
	for (int k = 1; k <= K; k++) {
		if (k != j) {
			if (board[i - j][k]) { board[i][j] = false; return; }
		}
	}
	
	board[i][j] = true;
}

void setting(int P, int K, int S) {
	for (int i = 1; i <= S; i++) {
		if (i % P != 0 || i == S) {
			for (int j = 1; j <= K; j++) {
				if(i - j >= 0) set_feild(P, K, i, j);
			}
		}
	}
}

int result(int K, int S) {
	for (int i = 1; i <= K; i++) {
		if (board[S][i]) return S - i;
	}

	return -1;
}

int main() {
	ifstream inp("coinmove.inp");
	ofstream out("coinmove.out");

	int T, P, K, S;

	inp >> T;
	while (T--) {
		inp >> P >> K >> S;
		setting(P, K, S);
		out << result(K, S) << '\n';

		for (int i = 1; i <= S; i++) {
			for (int j = 1; j <= 8; j++) out << board[i][j] << ' ';
			out << '\n';
		}
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= S; j++) board[i][j] = false;
		}
	}

	inp.close();
	out.close();
	return 0;
}