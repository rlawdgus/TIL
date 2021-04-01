#include <stdio.h>
#pragma warning (disable : 4996)

typedef struct vertex {
	int weight;
	int visit;
}Vertex;

Vertex vertex[10000][10000];
int stack[10000];
int top = -1;
int queue[10000];
int front = -1, rear = -1;

int DFS(int n, int m, int start) {
	int total = 0, cnt = 0, check = 0;
	stack[0] = start, top++;

	for (int i = start, j = 0, k;; j++) {
		if (j > n) continue;
		if (vertex[i][j].weight != 0 && vertex[i][j].visit == 0) {
			for (k = 0; k <= top; k++) if (stack[k] == j) check = 1;
			if (!check) { total += vertex[i][j].weight; stack[++top] = j; }
			vertex[i][j].visit = 1, vertex[j][i].visit = 1;
			check = 0;
			cnt++;
			if (j != start) i = j;
			j = -1;
		}

		if (j == n - 1) {
			i = stack[top--];
			j = -1;
		}

		if (cnt == m) break;
	}

	return total;
}

int BFS(int n, int start) {
	int total = 0, cnt = 0, check = 0;
	stack[0] = start, top++;

	for (int i = start, j = 0, k;; j++) {
		if (vertex[i][j].weight != 0 && vertex[i][j].visit == 0) {
			for (k = 0; k <= top; k++) if (stack[k] == j) check = 1;
			if (!check) { total += vertex[i][j].weight; queue[++rear] = j; stack[++top] = j; }
			vertex[i][j].visit = 1, vertex[j][i].visit = 1;
			check = 0;
			cnt++;
		}

		if (j == n - 1) {
			i = queue[++front];
			j = -1;
		}

		if (cnt == n) break;
	}

	return total;
}

int main() {
	FILE *inp = fopen("graph.inp", "rt");
	FILE *out = fopen("graph.out", "wt");

	int T, n, m, u, v, w, k, start, dfs, bfs;

	fscanf(inp, "%d", &T);
	while (T--) {
		fscanf(inp, "%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			fscanf(inp, "%d %d %d", &u, &v, &w);
			vertex[u][v].weight = w;
			vertex[v][u].weight = w;
		}

		fscanf(inp, "%d", &k);
		while (k--) {
			fscanf(inp, "%d", &start);

			dfs = DFS(n, m, start);
			for (int j = 0; j < n; j++) for (int l = 0; l < n; l++) vertex[j][l].visit = 0;
			top = -1;
			bfs = BFS(m, start);
			for (int j = 0; j < n; j++) for (int l = 0; l < n; l++) vertex[j][l].visit = 0;
			top = -1, front = -1, rear = -1;
			fprintf(out, "n=%d m=%d start=%d DFS:%d BFS:%d\n", n, m, start, dfs, bfs);
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}