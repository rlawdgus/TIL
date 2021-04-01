#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("dice.inp", "rt");
	FILE *out = fopen("dice.out", "wt");

	int board[10000][6];
	int N, flr, top, max = 0, sum = 0, res = 0;
	fscanf(inp, "%d", &N);

	for (int i = 0; i < N; i++) for (int j = 0; j < 6; j++) fscanf(inp, "%d", &board[i][j]);

	for (int i = 0; i < 6; i++) {
		flr = i;
		for (int j = 0; j < N; j++) {
			switch (flr) {
			case 0: top = 5; break;
			case 1: top = 3; break;
			case 2: top = 4; break;
			case 3: top = 1; break;
			case 4: top = 2; break;
			default: top = 0;
			}

			for (int k = 0; k < 6; k++) {
				if (k == flr || k == top) continue;
				max = max > board[j][k] ? max : board[j][k];
			}

			sum += max;
			max = 0;
			
			for (int k = 0; k < 6; k++) if (board[j + 1][k] == board[j][top]) { flr = k; break; }
		}
		res = res > sum ? res : sum;
		sum = 0;
	}

	fprintf(out, "%d", res);

	fclose(inp);
	fclose(out);
	return 0;
}