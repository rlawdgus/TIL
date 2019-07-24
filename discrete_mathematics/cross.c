#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("cross.inp", "rt");
	FILE *out = fopen("cross.out", "wt");

	int T, N, n, S_1[10001], S_2[10001], result = 0;
	fscanf(inp, "%d", &T);

	for (int t = 0; t < T; t++) {
		fscanf(inp, "%d", &N);

		for (int i = 1; i <= N; i++) {
			fscanf(inp, "%d", &n);
			S_1[n] = i;
		}
		for (int i = 1; i <= N; i++) {
			fscanf(inp, "%d", &n);
			S_2[n] = i;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if ((S_1[i] > S_1[j]) && (S_2[i] < S_2[j])) result++;
			}
		}

		fprintf(out, "Case %d: %d\n", t + 1, result);
		result = 0;
	}

	fclose(inp);
	fclose(out);
	return 0;
}