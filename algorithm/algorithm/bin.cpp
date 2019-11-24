#include <fstream>
#include <cstring>
#include <algorithm>
#define INF 9999999
using namespace std;

int local[501];
int board[501][501];
int board2[501][501];

int set_distance(int start, int dest) {
	int result = 0, mid = (start + dest + 1) / 2, tmp;

	for (int i = start; i <= dest; i++) {
		tmp = local[mid] - local[i];
		if (tmp < 0) result += tmp * -1;
		else if (tmp > 0) result += tmp;
	}

	return result;
}

void set_board(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) board[i][j] = set_distance(i, j);
	}
}

void set_board2(int n, int m){
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= i; k++) {
				board2[i][j] = min(board2[i][j], board2[k - 1][j - 1] + board[k][i]);
			}
		}
	}
}

int main() {
	ifstream inp("bin.inp");
	ofstream out("bin.out");

	int T, n, m;

	inp >> T;

	while (T--) {
		inp >> n >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				board2[i][j] = INF;
			}
		}
		memset(board, 0, sizeof(board));	

		for (int i = 1; i <= n; i++) inp >> local[i];
		
		sort(local, local + n + 1);

		set_board(n);
		
		set_board2(n, m);
		
		out << board2[n][m] << '\n';
	}

	inp.close();
	out.close();
	return 0;
}