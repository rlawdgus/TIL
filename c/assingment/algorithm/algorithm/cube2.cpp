#include <fstream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int board[201][201][201];

void setting() {
	for (int x = 1; x < 201; x++) {
		for (int y = 1; y < 201; y++) {
			for (int z = 1; z < 201; z++) {
				if (x == y && y == z) board[x][y][z] = 1;
				else board[x][y][z] = INF;
			}
		}
	}
}

void setting2() {
	for (int x = 1; x < 201; x++) {
		for (int y = x; y < 201; y++) {
			for (int z = y; z < 201; z++) {
				for (int i = 1; i < x / 2 + 1; i++) {
					board[x][y][z] = min(board[x][y][z], board[i][y][z] + board[x - i][y][z]);
				}

				for (int i = 1; i < y / 2 + 1; i++) {
					board[x][y][z] = min(board[x][y][z], board[x][i][z] + board[x][y - i][z]);
				}

				for (int i = 1; i < z / 2 + 1; i++) {
					board[x][y][z] = min(board[x][y][z], board[x][y][i] + board[x][y][z - i]);
				}

				board[x][z][y] = board[x][y][z];
				board[y][x][z] = board[x][y][z];
				board[y][z][x] = board[x][y][z];
				board[z][x][y] = board[x][y][z];
				board[z][y][x] = board[x][y][z];
			}
		}
	}
}

int main() {
	ifstream inp("cube2.inp");
	ofstream out("cube2.out");

	int T, W, L, H;

	setting();
	setting2();

	inp >> T;
	while (T--) {
		inp >> W >> L >> H;
		out << board[W][L][H] << '\n';
	}

	inp.close();
	out.close();
	return 0;
}