#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("hw2.inp", "rt");
	FILE *out = fopen("hw2.out", "wt");

	if ((inp = fopen("hw2.inp", "rt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw2.inp");
	if ((out = fopen("hw2.out", "wt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw2.out");

	int table[100] = { 0 };
	int N, index, num;
	double alpha, tmp;

	fscanf(inp, "%d %lf", &N, &alpha);

	while (fscanf(inp, "%d", &num)) {
		tmp = num * alpha;
		tmp = tmp - floor(tmp);
		tmp *= 100;
		tmp += 0.5;
		tmp = floor(tmp);
		tmp *= N;
		tmp /= 100;
		index = (int)tmp;

		for (int i = index;; i++) {
			if (table[i] == 0) { table[i] = num; break; }
			else if (i == N - 1) i = -1;
		}
	}

	for (int i = 0; i < N; i++) { if (table[i] != 0) fprintf(out, "[%d,%d]\n", i, table[i]); }
	fprintf(out, "*");

	fclose(inp);
	fclose(out);
	return 0;
}