#include <fstream>
#include <vector>
using namespace std;

vector< vector< int > > vertex(1000000);
int visit[1000000]; //0: 방문 안함, 1: red, 2: blue

void max_DFS(int start, int color) {
	visit[start] = color;

	for (int i = 0; i < vertex[start].size(); i++) {
		int next = vertex[start][i];

		if (visit[next] == 0) max_DFS(next, 3 - color);
	}
}

bool check(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < vertex[i].size(); j++) {
			int next = vertex[i][j];

			if (visit[i] == visit[next]) return true;
		}
	}

	return false;
}

int main() {
	ifstream inp("cycle.inp");
	ofstream out("cycle.out");

	int T, n, m, a, b;

	inp >> T;
	while (T--) {
		inp >> n >> m;

		while (m--) {
			inp >> a >> b;
			vertex[a].push_back(b);
			vertex[b].push_back(a);
		}
		max_DFS(0, 1);

		if (check(n)) out << "O\n";
		else out << "X\n";

		for (int i = 0; i < n; i++) visit[i] = 0;
		vertex.clear();
		vertex.resize(1000000);
	}

	inp.close();
	out.close();
	return 0;
}