#include <fstream>
using namespace std;

int main() {
	ifstream inp("enterance.inp");
	ofstream out("enterance.out");

	int T, N, n, board[1000] = { 0 }, cnt = 0;

	inp >> T;
	while (T--) {
		inp >> N;
		
		for (int i = 0; i < N; i++) {
			inp >> n;

			for (int j = 0;; j++) {
				if (board[j] < n) { board[j] = n; break; }
			}
		}
		
		for (int i = 0; board[i] != 0; i++) { board[i] = 0; cnt++; }
		out << cnt << '\n';
		cnt = 0;
	}

	inp.close();
	out.close();
	return 0;
}