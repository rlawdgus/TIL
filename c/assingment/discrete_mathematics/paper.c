#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("paper.inp", "rt");
	FILE *out = fopen("paper.out", "wt");

	int T, N, M, cnt = 0, result = 1;
	int nm[50][99] = { 0 };
	fscanf(inp, "%d", &T);

	while (T--) {
		fscanf(inp, "%d %d", &N, &M);
		for (int i = 0; i < N; i++) for (int j = 1; j < 2 * M - 1; j += 2) fscanf(inp, "%d", &nm[i][j]);
		for (int i = 1; i < N; i++) for (int j = 0; j < 2 * M - 1; j += 2) fscanf(inp, "%d", &nm[i][j]);
		
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < 2 * M - 1; j += 2) {
				if (nm[i - 1][j] == 1) cnt++;
				if (nm[i][j - 1] == 1) cnt++;
				if (nm[i][j] == 1) cnt++;
				if (nm[i][j + 1] == 1) cnt++;
				
				if (cnt % 2 == 0) { result = 0; break; }

				cnt = 0;
			}
			if (result == 0) break;
		}

		fprintf(out, "%d ", result);
		result = 1;
	}

	fclose(inp);
	fclose(out);
	return 0;
}