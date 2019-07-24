#include <stdio.h>
#pragma warning (disable : 4996)

//int n[1000][1000];

int main() {
	FILE *inp = fopen("block.inp", "rt");
	FILE *out = fopen("block.out", "wt");

	int T, N, n[1000][1000];
	fscanf(inp, "%d", &T);

	while (T--) {
		fscanf(inp, "%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf(inp, "%d", &n[i][j]);
				if (i == j) break;
			}
		}

		for (int a = 0; a < N; a++) {
			for (int i = N - 1; i > 0; i--) {
				for (int j = i; j > 0; j--) {
					if ((n[i][j] == -1 && n[i][j - 1] == -1)
						|| (n[i][j] == -1 && n[i - 1][j - 1] == -1)
						|| (n[i][j - 1] == -1 && n[i - 1][j - 1] == -1)) continue;
					else if (n[i][j] == -1) {
						if (n[i - 1][j - 1] - n[i][j - 1] >= 0) n[i][j] = n[i - 1][j - 1] - n[i][j - 1];
						else n[i][j] = n[i - 1][j - 1] - n[i][j - 1] + 100;
					}
					else if (n[i][j - 1] == -1) {
						if (n[i - 1][j - 1] - n[i][j] >= 0) n[i][j - 1] = n[i - 1][j - 1] - n[i][j];
						else n[i][j - 1] = n[i - 1][j - 1] - n[i][j] + 100;
					}
					else {
						n[i - 1][j - 1] = (n[i][j] + n[i][j - 1]) % 100;
					}
				}
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fprintf(out, "%d", n[i][j]);
				if (i == j) { fprintf(out, "\n"); break; }
				else fprintf(out, " ");
			}
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}