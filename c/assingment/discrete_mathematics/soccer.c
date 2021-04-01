#include <stdio.h>
#pragma warning (disable : 4996)

typedef struct Team {
	int rank;
	int point;
	int home, away;
	int lost;
}Team;

int main() {
	FILE *inp = fopen("soccer.inp", "rt");
	FILE *out = fopen("soccer.out", "wt");

	int T, n, k, X, Y, a, b;

	Team team[41];
	for (int i = 1; i <= 40; i++) {
		team[i].rank = 1;
		team[i].point = 0;
		team[i].home = 0;
		team[i].away = 0;
		team[i].lost = 0;
	}

	fscanf(inp, "%d", &T);

	for (int testcase = 1; testcase <= T; testcase++) {
		fscanf(inp, "%d %d", &n, &k);

		while (k--) {
			for (int i = 0; i < n * (n - 1); i++) {
				fscanf(inp, "%d %d %d %d", &X, &Y, &a, &b);
				Y *= -1;

				team[X].away += a;
				team[X].lost += b;
				team[Y].home += b;
				team[Y].lost += a;

				if (a > b) team[X].point += 3;
				else if (a < b) team[Y].point += 3;
				else {
					team[X].point++;
					team[Y].point++;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (team[i].point > team[j].point) team[j].rank++;
				else if (team[i].point < team[j].point) team[i].rank++;
				else {
					if (team[i].away + team[i].home - team[i].lost > team[j].away + team[j].home - team[j].lost) team[j].rank++;
					else if (team[i].away + team[i].home - team[i].lost < team[j].away + team[j].home - team[j].lost) team[i].rank++;
					else {
						if (team[i].away > team[j].away) team[j].rank++;
						else if (team[i].away < team[j].away) team[i].rank++;
						else {
							team[i].rank;
							team[j].rank;
						}
					}
				}
			}
		}

		fprintf(out, "Test Case #%d:", testcase);
		for (int i = 1; i <= n; i++) fprintf(out, " %d", team[i].rank);
		fprintf(out, "\n");

		for (int i = 1; i <= n; i++) {
			team[i].rank = 1;
			team[i].point = 0;
			team[i].home = 0;
			team[i].away = 0;
			team[i].lost = 0;
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}