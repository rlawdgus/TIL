#include <stdio.h>
#pragma warning (disable : 4996)

char *A = "000000";
char *B = "001111";
char *C = "010011";
char *D = "011100";
char *E = "100110";
char *F = "101001";
char *G = "110101";
char *H = "111010";

int compare(char *str, char *num) {
	int cnt = 0;
	for (int i = 0; i < 6; i++) if (str[i] != num[i]) cnt++;
	return cnt;
}

int main() {
	FILE *inp = fopen("mail.inp", "rt");
	FILE *out = fopen("mail.out", "wt");

	int T, N;
	char num[601];
	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(inp, "%d", &N);
		fscanf(inp, "%s", &num);

		for (int j = 0; j < 6 * N; j += 6) {
			if (compare(A, &num[j]) < 2) fprintf(out, "A");
			else if (compare(B, &num[j]) < 2) fprintf(out, "B");
			else if (compare(C, &num[j]) < 2) fprintf(out, "C");
			else if (compare(D, &num[j]) < 2) fprintf(out, "D");
			else if (compare(E, &num[j]) < 2) fprintf(out, "E");
			else if (compare(F, &num[j]) < 2) fprintf(out, "F");
			else if (compare(G, &num[j]) < 2) fprintf(out, "G");
			else if (compare(H, &num[j]) < 2) fprintf(out, "H");
			else fprintf(out, "X");
		}
		fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}