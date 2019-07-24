#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("sequence.inp", "rt");
	FILE *out = fopen("sequence.out", "wt");

	long long A, L;
	int cnt = 1;

	for (int i = 1;; i++) {
		fscanf(inp, "%lld %lld", &A, &L);
		if (A < 0 && L < 0) break;

		fprintf(out, "Case %d: A = %lld, limit = %lld, number of terms = ", i, A, L);

		while (1) {
			if (A == 1) break;

			if (A % 2 == 0) {
				A /= 2;
				cnt++;
			}
			else {
				A = A * 3 + 1;
				if (A > L) break;
				cnt++;
			}
		}

		fprintf(out, "%d\n", cnt);
		cnt = 1;
	}

	fclose(inp);
	fclose(out);
	return 0;
}