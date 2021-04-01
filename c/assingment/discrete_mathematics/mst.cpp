#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Vertex { int dest, weight; }Vertex;
vector< vector< Vertex > > graph;
vector< Vertex > result;
vector< bool > visit;

bool operator<(const Vertex &a, const Vertex &b) {
	if (a.weight == b.weight) return a.dest > b.dest;
	return a.weight > b.weight;
}

bool compare(const Vertex &a, const Vertex &b) {
	if (a.dest == b.dest) return a.weight < b.weight;
	return a.dest < b.dest;
}

priority_queue< Vertex > heap;

int cnt = 0;

void prim(int start, int tmp) {
	visit[start] = true;
	cnt++;
	//시작점의 인접노드
	for (int i = 0; i < graph[start].size(); i++) {
		if (!visit[graph[start][i].dest]) {
			heap.push(graph[start][i]);
		}
	}

	if (heap.empty()) result.push_back({ cnt, tmp });
	else {
		int next = heap.top().dest;
		if (!visit[next]) tmp += heap.top().weight;
		else cnt--;
		heap.pop();
		prim(next, tmp);
	}
}

int main() {
	ifstream inp("mst.inp");
	ofstream out("mst.out");

	int n, m, u, v, w;

	inp >> n >> m;
	graph.resize(n);
	visit.resize(n);
	while (m--) {
		inp >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			prim(i, 0);
			cnt = 0;
		}
	}

	sort(result.begin(), result.end(), compare);

	for (int i = 0; i < result.size(); i++)
		out << result[i].dest << ' ' << result[i].weight << '\n';

	inp.close();
	out.close();
	return 0;
}