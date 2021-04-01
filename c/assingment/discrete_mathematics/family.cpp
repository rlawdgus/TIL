#include <fstream>
#include <vector>
using namespace std;

vector< vector< int > > vertex(500001);
int visit[500001];
int maximum = 0;
int tmp = 0;


int DFS(int start) {
	visit[start] = 1;

	for (int i = 0; i < vertex[start].size(); i++) {
		int next = vertex[start][i];

		if (visit[next] == 0) { tmp++; DFS(next); }
	}

	maximum = maximum > tmp ? maximum : tmp;
	tmp--;
	return maximum + 1;
}



int main() {
	ifstream inp("family.inp");
	ofstream out("family.out");

	int T, a, b;
	long long N, total, b_total = 0;

	inp >> T;
	while (T--) {
		inp >> N;
		total = N * (N + 1) / 2;

		for (int i = 0; i < N - 1; i++) {
			inp >> a >> b;
			vertex[a].push_back(b);

			b_total += b;
		}

		out << DFS(total - b_total) << '\n';

		b_total = 0;
		for (int i = 1; i <= N; i++) visit[i] = 0;
		maximum = 0;
		tmp = 0;
		vertex.clear();
		vertex.resize(500001);
	}

	inp.close();
	out.close();
	return 0;
}