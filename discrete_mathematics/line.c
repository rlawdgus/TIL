#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("line.inp", "rt");
	FILE *out = fopen("line.out", "wt");

	int T, M, cnt = 0, tmp3;
	double Q, A, max = 1000000000, min = 0, tmp, tmp2;
	fscanf(inp, "%d", &T);

	while (T--) {
		fscanf(inp, "%d", &M);
		tmp3 = M;
		while (M--) {
			fscanf(inp, "%lf %lf", &Q, &A);

			if (A == 1) { cnt++; continue; }
			tmp = (Q - 1 - (A * (A - 1) / 2) + (A - 1)) / (A - 1);
			tmp2 = (Q - (A * (A - 1) / 2)) / A;
			max = max < floor(tmp) ? max : floor(tmp);
			min = min > ceil(tmp2) ? min : ceil(tmp2);
			

			cnt++;
			if (max == min) break;
		}
		
		if (max != min) fprintf(out, "-1\n");
		else fprintf(out, "%d %d\n", cnt, (int)max);

		while (tmp3 != cnt) { fscanf(inp, "%lf %lf", &Q, &A); cnt++; }

		max = 1000000000, min = 0, cnt = 0;
	}

	fclose(inp);
	fclose(out);
	return 0;
}