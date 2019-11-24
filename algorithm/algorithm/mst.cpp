#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct kruskal_vertex {
	int u;
	int v;
	int w;
	int num;
};

kruskal_vertex board[100001];
int parent[10001];
int tmp[100001];
int tmp_size;

int get_parent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = get_parent(parent[a]);
}

void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);

	/*if (a < b)*/ parent[b] = a;
	//else parent[a] = b;	//??
}

bool find(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);

	if (a == b) return true;
	return false;
}

void kruskal(ofstream& out, int n, int m) {
	tmp_size = 0;
	int result = 0;

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		if (!find(board[i].u, board[i].v)) {
			result += board[i].w;
			union_parent(board[i].u, board[i].v);
			tmp[tmp_size++] = board[i].num;
		}
	}

	out << "Tree edges by Kruskal algorithm: " << result << '\n';

	for (int i = 0; i < tmp_size; i++) out << tmp[i] << '\n';
}

bool compare(kruskal_vertex a, kruskal_vertex b) {
	if (a.w == b.w) return a.num < b.num;
	return a.w < b.w;
}

struct prim_vertex {
	int u;
	int v;
	int w;
	int num;
};

bool operator<(prim_vertex a, prim_vertex b) {
	if (a.w == b.w) return a.num > b.num;
	return a.w > b.w;
}

vector< prim_vertex > graph[10001];

void prim(ofstream& out, int start, int n) {

	int result = 0;
	priority_queue<prim_vertex> prim_pq;
	vector<int> edge_order;
	vector<bool> visited(n);
	prim_pq.push({ 0,start,0,0 });

	while (!prim_pq.empty()) {
		int u = prim_pq.top().u;
		int v = prim_pq.top().v;
		int w = prim_pq.top().w;
		int idx = prim_pq.top().num;
		prim_pq.pop();

		if (visited[v]) continue;
		result += w;
		edge_order.push_back(idx);
		visited[v] = true;

		for (int i = 0; i < graph[v].size(); i++) {
			if (!visited[graph[v][i].v]) {
				prim_pq.push(graph[v][i]);
			}
		}
	}

	out << "Tree edges by Prim algorithm with starting vertex " << start << ": " << result << "\n";
	for (int i = 1; i < edge_order.size(); i++)
		out << edge_order[i] << "\n";
	return;
}

int main() {
	ifstream inp("mst.inp");
	ofstream out("mst.out");

	int n, m, u, v, w;

	inp >> n >> m;
	for (int i = 0; i < m; i++) {
		inp >> u >> v >> w;

		board[i].u = u;
		board[i].v = v;
		board[i].w = w;
		board[i].num = i;

		graph[u].push_back({ u, v, w, i });
		graph[v].push_back({ v, u, w, i });
	}

	sort(board, board + m, compare);
	kruskal(out, n, m);
	prim(out, 0, n);
	prim(out, n / 2, n);
	prim(out, n - 1, n);

	inp.close();
	out.close();
	return 0;
}