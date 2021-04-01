#include <stdio.h>
#pragma warning (disable : 4996)

typedef struct river {
	char S;
	int dis;
	int fall;
}river;

river r[110];

int stepback(int max, int dest, int start, int pre) {
	for (int i = dest; i >= start; i--) {
		if (r[i].fall == 0) {
			max = max > r[pre].dis - r[i].dis ? max : r[pre].dis - r[i].dis;
			pre = i;
		}
	}

	return max;
}

int step(int max, int start, int dest, int pre) {
	for (int i = start; i <= dest + 1;) {
		if (r[i].S == 'B') {
			max = max > r[i].dis - r[pre].dis ? max : r[i].dis - r[pre].dis;
			pre = i;
			i++;
		}
		else {
			max = max > r[i].dis - r[pre].dis ? max : r[i].dis - r[pre].dis;
			pre = i;
			r[i].fall = 1;

			if (r[i + 1].S == 'B') i++;
			else i += 2;
		}
	}
	int temp = stepback(max, dest, start, pre);
	max = max > temp ? max : temp;
	return max;
}

int main() {
	FILE *inp = fopen("frog.inp", "rt");
	FILE *out = fopen("frog.out", "wt");

	int T, N, w, M;
	char enter, stone, bar;

	fscanf(inp, "%d", &T);
	for (int i = 0, j; i < T; i++) {
		r[0].S = 'B', r[0].dis = 0;
		fscanf(inp, "%d %d", &N, &w);

		for (j = 1; j <= N; j++) {
			fscanf(inp, "%c%c%c%d", &enter, &stone, &bar, &M);
			r[j].S = stone, r[j].dis = M;
		}
		r[N + 1].S = 'B', r[N + 1].dis = w;

		fprintf(out, "Case %d: %d\n", i + 1, step(0, 0, N, 0));

		for (int i = 0; i <= N + 1; i++) { r[i].S = 0, r[i].dis = 0, r[i].fall = 0; }
	}

	fclose(inp);
	fclose(out);
	return 0;
}