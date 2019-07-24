#include <stdio.h>
#pragma warning (disable : 4996)

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

int main() {
	FILE *inp = fopen("line2.inp", "rt");
	FILE *out = fopen("line2.out", "wt");

	int T, n, board[2][1000], res[1000], tmp, tmp2;
	fscanf(inp, "%d", &T);

	while (T--) {
		fscanf(inp, "%d", &n);
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &board[0][i]);
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &board[1][i]);

		for (int i = n - 1; i >= 0; i--) {
			tmp = board[0][i];

			for (int j = 0; j < n; j++) {
				if (board[1][j] == tmp) {
					tmp2 = j;
					if (i - j < 0) res[tmp - 1] = j - i;
					else res[tmp - 1] = i - j;
					
					for (int k = j; k < i; k++) swap(&board[1][k], &board[1][k + 1]);
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) fprintf(out, "%d ", res[i]);
		fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}