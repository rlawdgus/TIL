#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

char arr[102][102];

int main() {
	FILE *inp = fopen("mine.inp", "rt");
	FILE *out = fopen("mine.out", "wt");
	int m, n, num = 1;
	char enter;
	
	while (1) {
		fscanf(inp, "%d", &m);
		fscanf(inp, "%d", &n);
		fscanf(inp, "%c", &enter);
		if (m == 0 && n == 0) break;

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n + 1; j++) {
				fscanf(inp, "%c", &arr[i][j]);
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] != '*') {
					arr[i][j] = 48;

					if (arr[i - 1][j - 1] == '*') arr[i][j]++;
					if (arr[i - 1][j] == '*') arr[i][j]++;
					if (arr[i - 1][j + 1] == '*') arr[i][j]++;

					if (arr[i][j - 1] == '*') arr[i][j]++;
					if (arr[i][j + 1] == '*') arr[i][j]++;

					if (arr[i + 1][j - 1] == '*') arr[i][j]++;
					if (arr[i + 1][j] == '*') arr[i][j]++;
					if (arr[i + 1][j + 1] == '*') arr[i][j]++;
				}
			}
		}
		
		fprintf(out, "Field #%d:\n", num++);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				fprintf(out, "%c", arr[i][j]);
			}
			fprintf(out, "\n");
		}
		memset(arr, 0, sizeof(arr));
		fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}