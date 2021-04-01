#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int water[1002][1002];
int row[1002][1002];
int col[1002][1002];
bool visited[1002][1002];

bool range_row(int i, int n) {
	if (i > 0 && i < n) return true;
	else return false;
}

bool range_col(int j, int m) {
	if (j > 0 && j < m) return true;
	else return false;
}

void change_water(int hole, int direction, int i, int j, int n, int m) {
	int change = hole;
	water[i][j] = min(water[i][j], change);
	visited[i][j] = true;

	if (range_row(i, n)) {
		if (row[i][j] != -1 && direction != 0 && visited[i - 1][j] == false) {
			change = max(water[i][j], row[i][j]);

			change_water(change, 3, i - 1, j, n, m);

		}
	}

	if (range_col(j, m)) {
		if (col[i][j] != -1 && direction != 1 && visited[i][j - 1] == false) {
			change = max(water[i][j], col[i][j]);
			change_water(change, 2, i, j - 1, n, m);
		}
	}

	if (range_col(j + 1, m)) {
		if (col[i][j + 1] != -1 && direction != 2 && visited[i][j + 1] == false) {
			change = max(water[i][j], col[i][j + 1]);
			change_water(change, 1, i, j + 1, n, m);
		}
	}

	if (range_row(i + 1, n)) {
		if (row[i + 1][j] != -1 && direction != 3 && visited[i + 1][j] == false) {
			change = max(water[i][j], row[i + 1][j]);
			change_water(change, 0, i + 1, j, n, m);
		}
	}

	visited[i][j] = false;
}

void solve(int n, int m) {
	for (int i = 0; i < m; i++) {
		if (row[0][i] != -1) {
			change_water(row[0][i], 0, 0, i, n, m);
		}
		if (row[n][i] != -1) {
			change_water(row[n][i], 3, n - 1, i, n, m);
		}
	}

	for (int i = 0; i < n; i++) {
		if (col[i][0] != -1) {
			change_water(col[i][0], 1, i, 0, n, m);
		}
		if (col[i][m] != -1) {
			change_water(col[i][m], 2, i, m - 1, n, m);
		}
	}
}

void init() {
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			row[i][j] = 0;
			col[i][j] = 0;
			water[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void setting(int n, int m, int h) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			water[i][j] = h;
		}
	}
}

int main() {
	ifstream inp("watertank.inp");
	ofstream out("watertank.out");

	int T, n, m, h, result;

	inp >> T;
	while (T--) {
		result = 0;
		inp >> n >> m >> h;

		setting(n, m, h);

		for (int j = 0; j < n + 1; j++) {
			for (int i = 0; i < m; i++) {
				inp >> row[j][i];
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m + 1; i++) {
				inp >> col[j][i];
			}
		}

		solve(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result += water[i][j];
			}
		}
		out << result << '\n';

		init();
	}

	inp.close();
	out.close();
	return 0;
}