#include <fstream>
#include <vector>
using namespace std;

typedef struct Vertex {
	int dest;
	int weight;
}Vertex;

vector< vector< Vertex > > vertex;
vector< int > stack;	//가중치 누적
int top = -1;

int max_DFS(int start, int maximum) {
	for (int i = 0; i < vertex[start].size(); i++) {
		int next = vertex[start][i].dest;
		stack[++top] = vertex[start][i].weight;

		maximum = max_DFS(next, maximum);
	}

	int tmp = 0;
	for (int i = 0; i <= top; i++) tmp += stack[i];
	maximum = maximum > tmp ? maximum : tmp;
	top--;
	return maximum;
}

int update_DFS(int start, int maximum) {	//maixmum = 31
	int total = 0;	//그 라인 깊이
	int result = 0;	//갱신값 다 합칠 거 = 66

	for (int i = 0; i < vertex[start].size(); i++) {
		if (vertex[vertex[start][i].dest].size() == 0) { //자식이 없을 때
			if (vertex[start][i].weight < maximum) {	//최대길이보다 짧으면 
				result += maximum - vertex[start][i].weight;	//그 차이만큼
			}
		}
		else {	//자식이 있을 때
			total = vertex[start][i].weight + max_DFS(vertex[start][i].dest, 0);
			top = -1;
			int tmp = maximum - total;	// tmp는 그 간선에 더할 값
			result += tmp + update_DFS(vertex[start][i].dest, maximum - (tmp + vertex[start][i].weight));
			//			그 노드에 더할 값 +			자식노드에서 재귀, 31말고 
		}
	}

	return result;
}

int main() {
	ifstream inp("tree2.inp");
	ofstream out("tree2.out");

	int T, n, p, w;
	inp >> T;
	while (T--) {
		inp >> n;
		int maximum = 0;
		vertex.resize(n);
		stack.resize(n);

		for (int i = 1; i < n; i++) {
			inp >> p >> w;

			Vertex vt;
			vt.dest = i;
			vt.weight = w;

			vertex[p].push_back(vt);
		}

		maximum = max_DFS(0, maximum);
		top = -1;

		out << update_DFS(0, maximum) << '\n';

		vertex.clear();
		stack.clear();
	}

	inp.close();
	out.close();
	return 0;
}