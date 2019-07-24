#include <stdio.h>
#pragma warning (disable : 4996)

int goodCompare(char *G, char Q) {		//알파벳이 좋은문자면 1 아니면 0;
	for (int i = 0;; i++) {
		if (G[i] == '\0') return 0;
		if (G[i] == Q) return 1;
	}
}

int badCompare(char *G, char *Q, int badPoint, int end) {	//나쁜문자 조건에 맞으면 1 아니면 0
	int check = 0;

	for (int i = 0;; i++) {
		if (G[i] == '\0') break;
		for (int j = badPoint; j < badPoint + end; j++) if (G[i] == Q[j]) check++;
	}

	if (check <= end - 1) return 1;
	else return 0;
}

int length(char *str) {
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++) cnt++;
	return cnt;
}

char *exam(char *G, char *P, char *Q) {
	for (int i = 0, j = 0; ; i++) { //P[i] Q[j]
		if (Q[j] == '\0') return "Yes";

		if (P[i] == '?') {
			if (!goodCompare(G, Q[j])) return "No";
			j++;
		}
		else if (P[i] == '*') {
			int starLength = length(Q) - length(P) + 1;
			if (starLength > 1) {
				if (!badCompare(G, Q, i, starLength)) return "No";
			}
			else if (starLength == 1) {
				if(goodCompare(G, Q[j])) return "No";
			}
			j += starLength;
		}
		else {
			if (P[i] != Q[j]) return "No";
			j++;
		}
	}
}

int main() {
	FILE *inp = fopen("exam.inp", "rt");
	FILE *out = fopen("exam.out", "wt");

	int T, q;
	char G[27], P[1001], Q[1001];

	fscanf(inp, "%d", &T);
	for (int i = 0; i < T; i++) {
		fprintf(out, "Test Case: #%d\n", i + 1);
		fscanf(inp, "%s", G);
		fscanf(inp, "%s", P);
		fscanf(inp, "%d", &q);
		while (q--) {
			fscanf(inp, "%s", Q);
			fprintf(out, "%s\n", exam(G, P, Q));
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}