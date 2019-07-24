#include <fstream>
using namespace std;
#define MAX 10000
#define INF 2147483647

typedef struct Vertex {
	int visit;
	int distance;
	int pre;
}Vertex;

Vertex vertex[MAX];
int board[MAX][MAX];
int sequence[10000000][2];
int stack[MAX];
int top = -1;

int main() {
	ifstream inp("dijkstra.inp");
	ofstream out("dijkstra.out");

	int n, m, a, b, w, start = 0, min, minIndex;

	inp >> n >> m;
	for (int i = 0; i < m; i++) {
		inp >> a >> b >> w;
		board[a][b] = w;
		sequence[i][0] = a;
		sequence[i][1] = b;
	}

	for (int i = 0; i < n; i++) {
		vertex[i].visit = 0;
		vertex[i].distance = INF;
		vertex[i].pre = -1;
	}
	vertex[start].distance = 0;

	for (int k = 0; k < n; k++) {
		min = INF;

		for (int i = 0; i < n; i++) {
			if (vertex[i].visit == 0 && min > vertex[i].distance) {
				min = vertex[i].distance;
				minIndex = i;
			}
		}
		vertex[minIndex].visit = 1;

		for (int i = 0; i < n; i++) {
			if (board[minIndex][i] != 0) {
				if (vertex[i].distance == board[minIndex][i] + vertex[minIndex].distance) {
					for (int j = m; j >= 0; j--) {
						if ((sequence[j][0] == minIndex && sequence[j][1] == i)) {
							vertex[i].distance = board[minIndex][i] + vertex[minIndex].distance;
							vertex[i].pre = minIndex;
							break;
						}
						else if ((sequence[j][0] == vertex[i].pre && sequence[j][1] == i)) break;
					}
				}
				else if (vertex[i].distance > board[minIndex][i] + vertex[minIndex].distance) {
					vertex[i].distance = board[minIndex][i] + vertex[minIndex].distance;
					vertex[i].pre = minIndex;
				}
			}
		}
	}

	for (int i = 0, j; i < n; i++) {
		if (i == start) continue;

		j = i;
		while (1) {
			if (vertex[j].distance == INF) { stack[++top] = j; break; }
			if (vertex[j].pre == -1) break;
			stack[++top] = j;
			j = vertex[j].pre;
		}

		out << "V0 ";
		for (int k = top; k >= 0; k--) out << "V" << stack[k] << " ";
		if (vertex[i].distance != INF) out << "(" << vertex[i].distance << ")" << '\n';
		else out << "(-1)\n";
		top = -1;
	}

	//출력
	for (i = 0; i < n; i++)
	{
		if (i == start)
			continue;
		//경로 출력
		j = i, l = 0;
		while (1)
		{
			if (node[j].m_parent == -1)
			{
				print[l++] = j;
				break;
			}
			else
			{
				print[l++] = j;
				j = node[j].m_parent;
			}
		}
		for (k = l - 1; k >= 0; k--)
		{
			if (node[i].m_distance == INF)
			{
				fprintf(output, "V0 V%d ", print[k]);
			}
			else
			{
				fprintf(output, "V%d ", print[k]);
			}
		}
		if (node[i].m_distance == INF)
		{
			fprintf(output, "(-1)\n");
		}
		else
		{
			fprintf(output, "(%d)\n", node[i].m_distance);
		}

	}


	inp.close();
	out.close();
	return 0;
}