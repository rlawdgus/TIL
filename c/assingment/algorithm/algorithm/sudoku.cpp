#include <fstream>
#include <cstring>
#define MAX 10
using namespace std;

struct node {
	int x;
	int y;
};

int result[MAX][MAX];
bool row[MAX][MAX], col[MAX][MAX], visited[MAX][MAX];
char board[MAX][MAX];
node blank[81];
int blank_size;

void solve(ofstream& out, int blank_num, int t) {
	if (blank_num == blank_size) {
		out << "Test Case No: " << t << '\n';
		for (int i = 1; i < MAX; i++) {
			for (int j = 1; j < MAX; j++) {
				out << result[i][j] << ' ';
			}
			out << '\n';
		}
		out << '\n';
		return;
	}

	int x = blank[blank_num].x;
	int y = blank[blank_num].y;

	for (int i = 1; i < MAX; i++) {
		if (row[x][i] || col[y][i]) continue;

		if (!visited[board[x][y] - 'a'][i]) {
			row[x][i] = true;
			col[y][i] = true;
			visited[board[x][y] - 'a'][i] = true;
			result[x][y] = i;

			solve(out, blank_num + 1, t);

			result[x][y] = 0;
			visited[board[x][y] - 'a'][i] = false;
			col[y][i] = false;
			row[x][i] = false;
		}
	}
}

int main() {
	ifstream inp("sudoku.inp");
	ofstream out("sudoku.out");

	int T, num;
	char ch;

	inp >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 1; i < MAX; i++) {
			for (int j = 1; j < MAX; j++) {
				inp >> num;
				if (num == 0) blank[blank_size++] = { i, j };
				else {
					result[i][j] = num;
					row[i][num] = true;
					col[j][num] = true;
				}
			}
		}
		for (int i = 1; i < MAX; i++) {
			for (int j = 1; j < MAX; j++) {
				inp >> ch;
				board[i][j] = ch;

				if (result[i][j] != 0) visited[ch - 'a'][result[i][j]] = true;
			}
		}

		solve(out, 0, t);

		memset(result, 0, sizeof(result));
		memset(row, false, sizeof(row));
		memset(col, false, sizeof(col));
		memset(visited, false, sizeof(visited));
		memset(board, NULL, sizeof(board));
		blank_size = 0;
	}

	inp.close();
	out.close();
	return 0;
}