#include <fstream>
#include <vector>
using namespace std;

typedef struct Vertex {
	int dest;
	int weight;
}Vertex;

vector< vector< Vertex > > vertex;
vector< int > stack;	//����ġ ����
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
	int total = 0;	//�� ���� ����
	int result = 0;	//���Ű� �� ��ĥ �� = 66

	for (int i = 0; i < vertex[start].size(); i++) {
		if (vertex[vertex[start][i].dest].size() == 0) { //�ڽ��� ���� ��
			if (vertex[start][i].weight < maximum) {	//�ִ���̺��� ª���� 
				result += maximum - vertex[start][i].weight;	//�� ���̸�ŭ
			}
		}
		else {	//�ڽ��� ���� ��
			total = vertex[start][i].weight + max_DFS(vertex[start][i].dest, 0);
			top = -1;
			int tmp = maximum - total;	// tmp�� �� ������ ���� ��
			result += tmp + update_DFS(vertex[start][i].dest, maximum - (tmp + vertex[start][i].weight));
			//			�� ��忡 ���� �� +			�ڽĳ�忡�� ���, 31���� 
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