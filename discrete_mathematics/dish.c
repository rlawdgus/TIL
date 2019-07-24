#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("dish.inp", "rt");
	FILE *out = fopen("dish.out", "wt");

	int T, N, h = 10;
	char dish[1001] = { 0 };
	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(inp, "%d", &N);
		fscanf(inp, "%s", &dish);

		for (int j = 1; j < N; j++) {
			if (dish[j] == 0) break;

			if (dish[j - 1] == dish[j]) h += 5;
			else h += 10;
		}
		fprintf(out, "%d", h);
		h = 10;

		if (i != T - 1) fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}