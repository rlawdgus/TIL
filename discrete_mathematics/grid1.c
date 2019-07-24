#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("grid1.inp", "rt");
	FILE *out = fopen("grid1.out", "wt");

	int T, N, M, t, s, k, result;
	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(inp, "%d %d %d %d %d", &N, &M, &t, &s, &k);

		if (t == 1) {
			int line = (k - 1) / M, mod = k % M;

			if (s == 1) {
				result = M * (line + 1);

				if (line % 2 == 0) {
					result -= (M - mod);
					if (mod == 0) result += M;
				}
				else result -= (k - 1) % M;
			}
			else if (s == 2) {
				result = M * (line + 1);

				if (line % 2 == 0) result -= (k - 1) % M;
				else {
					result -= (M - mod);
					if (mod == 0) result += M;
				}
			}
			else if (s == 3) {
				result = (N * M) - (M * line);

				if (line % 2 == 0) result -= (k - 1) % M;
				else {
					result -= (M - mod);
					if (mod == 0) result += M;

				}
			}
			else {
				result = (N * M) - (M * line);

				if (line % 2 == 0) {
					result -= (M - mod);
					if (mod == 0) result += M;
				}
				else result -= (k - 1) % M;
			}
		}
		else {
			int line = (k - 1) / N, mod = k % N;

			if (s == 1) {
				result = 1 + line;

				if (line % 2 == 0) result += ((k - 1) % N) * M;
				else {
					result += ((N - 1) * M);
					result -= ((k - 1) % N) * M;
				}
			}
			else if (s == 2) {
				result = M - line;

				if (line % 2 == 0) result += ((k - 1) % N) * M;
				else {
					result += ((N - 1) * M);
					result -= ((k - 1) % N) * M;
				}
			}
			else if (s == 3) {
				result = N * M - line;

				if (line % 2 == 0) result -= ((k - 1) % N) * M;
				else {
					result -= ((N - 1) * M);
					result += ((k - 1) % N) * M;
				}
			}
			else {
				result = N * M - M + 1 + line;

				if (line % 2 == 0) result -= ((k - 1) % N) * M;
				else {
					result -= ((N - 1) * M);
					result += ((k - 1) % N) * M;
				}
			}
		}

		fprintf(out, "%d", result);

		if (i != T - 1) fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}