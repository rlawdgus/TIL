#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Vertex{
	int dest;
	int weight;
}Vertex;

vector< vector< Vertex > > graph(10000);
int visit[10000];
int stack[10000];
int top = -1;
int queue[10000];
int front = -1, rear = -1;

int max_DFS(int start, int n) {
	int total = 0, min = graph[start][0].dest, MI = 0, cnt = 0;
	visit[start] = 1, stack[++top] = start;

	for (int i = start, j = 0;; j++) {
		if (visit[graph[i][j].dest] == 0) {
			visit[graph[i][j].dest] = 1;		//정점 방문
			stack[++top] = graph[i][j].dest;	//스택에 방문한 정점 저장
			total += graph[i][j].weight;		//가중치 합산
			i = graph[i][j].dest;
			j = -1;
			cnt++;
		}
		else if (j == graph[i].size() - 1) {
			i = stack[--top];
			j = -1;
		}

		if (cnt == n - 1) break;
	}

	return total;
}

int BFS(int start, int n) {
	int total = 0, cnt = 0;

	visit[start] = 1;

	for (int i = start, j = 0;; j++) {
		if (visit[graph[i][j].dest] == 0) {
			visit[graph[i][j].dest] = 1;
			queue[++rear] = graph[i][j].dest;
			total += graph[i][j].weight;
			cnt++;
		}
		if (j == graph[i].size() - 1) {
			i = queue[++front];
			j = -1;
		}

		if (cnt == n - 1) break;
	}

	return total;
}

bool compare(Vertex a, Vertex b) {
	return a.dest < b.dest;
}
int main() {
	ifstream inp("graph.inp");
	ofstream out("graph.out");

	int T, n, m, u, v, w, k, s, dfs, bfs;

	inp >> T;
	while (T--) {
		inp >> n >> m;
		for (int i = 0; i < m; i++) {
			inp >> u >> v >> w;
			Vertex vt, vt2;
			vt.dest = v, vt.weight = w;
			vt2.dest = u, vt2.weight = w;
			graph[u].push_back(vt);
			graph[v].push_back(vt2);
		}
	
		for (int i = 0; i < n; i++) {
			sort(graph[i].begin(), graph[i].end(),compare);
		}
		inp >> k;
		while (k--) {
			inp >> s;

			dfs = max_DFS(s, n);
			top = -1;
			memset(visit, 0, sizeof(visit));
			bfs = BFS(s, n);
			front = -1, rear = -1;
			memset(visit, 0, sizeof(visit));
			out << "n=" << n << " m=" << m << " start=" << s << " DFS:" << dfs << " BFS:" << bfs << endl;
		}
		graph.clear();
		graph.resize(10000);
	}

	inp.close();
	out.close();
	return 0;
}