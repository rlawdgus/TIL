#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("primefactor.inp", "rt");
	FILE *out = fopen("primefactor.out", "wt");

	int T, n, tmp, result = 0;
	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(inp, "%d", &n);
		tmp = n;
		for (int j = 2; j <= n; j++) {
			if (j == n && n == tmp) { fprintf(out, "Prime Number"); break; }
			if (n % j == 0) {
				n /= j;
				result += j;
				if (n % j == 0) j--;
			}
		}
		if (n != tmp) fprintf(out, "%d", result);
		result = 0;

		if (i != T - 1) fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}