#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("string.inp", "rt");
	FILE *out = fopen("string.out", "wt");

	int T, ABA = 0, ABK = 0, BAB = 0, KBA = 0;
	char str[10001] = { 0 };
	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(inp, "%s", str);

		for (int i = 0;; i++) {
			if (str[i + 2] == 0) break;

			if (str[i] == 'A') {
				if (str[i + 1] == 'B') {
					if (str[i + 2] == 'A') ABA++;
				}
			}

			if (str[i] == 'A') {
				if (str[i + 1] == 'B') {
					if (str[i + 2] == 'K') ABK++;
				}
			}

			if (str[i] == 'B') {
				if (str[i + 1] == 'A') {
					if (str[i + 2] == 'B') BAB++;
				}
			}

			if (str[i] == 'K') {
				if (str[i + 1] == 'B') {
					if (str[i + 2] == 'A') KBA++;
				}
			}

		}
		fprintf(out, "%d %d %d %d\n", ABA, ABK, BAB, KBA);
		ABA = 0, ABK = 0, BAB = 0, KBA = 0;
	}

	fclose(inp);
	fclose(out);
	return 0;
}