#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("grid1.inp", "rt");
	FILE *out = fopen("grid1.out", "wt");

	int T, N, M, t, s, k;
	int result, cnt = 1, curve = 0;
	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(inp, "%d %d %d %d %d", &N, &M, &t, &s, &k);

		if (s == 1) result = 1;
		else if (s == 2) result = M;
		else if (s == 3) result = N * M;
		else result = N * M - M + 1;

		if (t == 1) {
			while (cnt < k) {
				if(cnt != 1 && M % cnt == 0) {
					if (s == 1 || s == 2) result += M;
					else result -= M;
					curve++;
				}
				if (curve % 2 == 0) {
					if (s == 1 || s == 4) result++;
					else result--;
				}
				else if (curve % 2 == 1) {
					if (s == 1 || s == 4) result--;
					else result++;
				}

				cnt++;
			}
			fprintf(out, "%d\n", result);
			cnt = 1;
			curve = 0;
		}
		else {
			while (cnt < k) {
				if (cnt != 1 && N % cnt == 0) {
					if (s == 1 || s == 4) result++;
					else result--;
					curve++;
				}
				if (curve % 2 == 0) {
					if (s == 1 || s == 2) result += M;
					else result -= M;
				}
				else if (curve % 2 == 1) {
					if (s == 1 || s == 2) result -= M;
					else result += M;
				}

				cnt++;
			}
			fprintf(out, "%d\n", result);
			cnt = 1;
			curve = 0;
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}