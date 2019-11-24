#include <fstream>
#include <vector>
using namespace std;

struct node {
	char ch;
	bool black;
	bool white;
	bool visit;
};

struct location {
	int i;
	int j;
};

node board[20][20];
vector< location > tmp;
int B, W;

void count(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j].black && !board[i][j].white) B++;
			else if (!board[i][j].black && board[i][j].white) W++;
		}
	}
}

void state_check() {
	bool b = false, w = false;
	int size = tmp.size(), x, y;

	for (int i = 0; i < size; i++) {
		x = tmp[i].j, y = tmp[i].i;
		if (board[y][x].black) b = true;
		if (board[y][x].white) w = true;

		if (b && w) break;
	}

	if (b && w) {
		for (int i = 0; i < size; i++) {
			x = tmp[i].j, y = tmp[i].i;
			board[y][x].black = true;
			board[y][x].white = true;
		}
	}
	else if (b) {
		for (int i = 0; i < size; i++) {
			x = tmp[i].j, y = tmp[i].i;
			board[y][x].black = true;
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			x = tmp[i].j, y = tmp[i].i;
			board[y][x].white = true;
		}
	}

	tmp.clear();
}

void check(int size, int i, int j) {
	board[i][j].visit = true;
	tmp.push_back({ i, j });

	if (i != 0) {	//╩С
		if (board[i - 1][j].ch == 'B') board[i][j].black = true;
		else if (board[i - 1][j].ch == 'W') board[i][j].white = true;
		else if (!board[i - 1][j].visit) check(size, i - 1, j);
	}

	if (i != size - 1) {	//го
		if (board[i + 1][j].ch =='B') board[i][j].black = true;
		else if (board[i + 1][j].ch == 'W') board[i][j].white = true;
		else if (!board[i + 1][j].visit) check(size, i + 1, j);
	}

	if (j != 0) {	//аб
		if (board[i][j - 1].ch == 'B') board[i][j].black = true;
		else if (board[i][j - 1].ch == 'W') board[i][j].white = true;
		else if (!board[i][j - 1].visit) check(size, i, j - 1);
	}

	if (j != size - 1) {	//©Л
		if (board[i][j + 1].ch == 'B') board[i][j].black = true;
		else if (board[i][j + 1].ch == 'W') board[i][j].white = true;
		else if (!board[i][j + 1].visit) check(size, i, j + 1);
	}
}

int main() {
	ifstream inp("go.inp");
	ofstream out("go.out");

	int k;
	char ch;

	inp >> k;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			inp >> board[i][j].ch;
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (board[i][j].ch == '.' && !board[i][j].visit) {
				check(k, i, j);
				state_check();
			}
		}
	}

	count(k);

	out << B << ' ' << W;

	inp.close();
	out.close();
	return 0;
}