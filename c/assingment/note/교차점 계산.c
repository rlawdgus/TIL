#include <stdio.h>
#pragma warning (disable : 4996)

int s1[10001];
int s2[10001];
int loca1[10001];
int loca2[10001];

int main() {
	FILE *inp = fopen("cross.inp", "rt");
	FILE *out = fopen("cross.out", "wt");

	int T, N;
	fscanf(inp, "%d", &T);
	for (int testcase = 0; testcase < T; testcase++) {
		fscanf(inp, "%d", &N);

		for (int i = 0; i < N; i++) {
			fscanf(inp, "%d", s1[i]);
			loca1[s1[i]] = loca1[i];
		}
		for (int i = 0; i < N; i++) {
			fscanf(inp, "%d", s2[i]);
			loca2[s2[i]] = loca2[i];
		}
		
		
	}

	fclose(inp);
	fclose(out);
	return 0;
}