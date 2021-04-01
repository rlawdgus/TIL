#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("matrix.inp", "rt");
	FILE *out = fopen("matrix.out", "wt");

	int T, n, m[300][300], result, tmp = 1;
	fscanf(inp, "%d", &T);

	while (T--) {
		fscanf(inp, "%d", &n);

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) fscanf(inp, "%d", &m[i][j]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (m[i][j] != 1) {
					int check = 1;
					for (int s = 0; s < n; s++) {
						for (int t = 0; t < n; t++) {
							if (m[i][s] + m[t][j] == m[i][j]) {
								check = 0;
								break;
							}
						}
						if (!check) break;
					}
					if (check) tmp = 0;
				}
				if (tmp == 0) break;
			}
			if (tmp == 0) break;
		}
		if (tmp == 1) result = 1;
		else result = 0;
		fprintf(out, "%d\n", result);

		tmp = 1;
	}
	fclose(inp);
	fclose(out);
	return 0;
}