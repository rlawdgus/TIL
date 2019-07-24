#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 10000
#define INF 2147483647

typedef struct Node
{
	int visit;
	int dis;
	int parent;
}Node;

Node node[MAX];
int map[MAX][MAX];
int print[MAX];
int seq[1000000][2];
int stack[MAX];
int top = -1;

int main()
{
	FILE *inp = fopen("dijkstra.inp", "r");
	FILE *out = fopen("dijkstra.out", "w");

	int n, m, a, b, c, start = 0, i, j, k, l, min, minindex;

	//입력
	fscanf(inp, "%d %d\n", &n, &m);
	for (i = 0; i < m; i++)
	{
		fscanf(inp, "%d %d %d\n", &a, &b, &c);
		map[a][b] = c;
		seq[i][0] = a;
		seq[i][1] = b;
	}

	//초기화
	for (i = 0; i < n; i++)
	{
		node[i].visit = 0;
		node[i].dis = INF;
		node[i].parent = -1;
	}
	node[start].dis = 0;

	//처리
	for (k = 0; k < n; k++)
	{
		min = INF;
		for (i = 0; i < n; i++)
		{
			if (node[i].visit == 0 && min > node[i].dis)
			{
				min = node[i].dis;
				minindex = i;
			}
		}
		node[minindex].visit = 1;

		for (i = 0; i < n; i++)
		{
			if (map[minindex][i] != 0 && node[i].dis == map[minindex][i] + node[minindex].dis)
			{
				for (int h = m; h >= 0; h--)  //끝에서부터 마지막에 가까운 간선번호 찾기
				{
					if ((seq[h][0] == minindex && seq[h][1] == i))
					{
						node[i].dis = map[minindex][i] + node[minindex].dis;
						node[i].parent = minindex;
						break;
					}
					else if ((seq[h][0] == node[i].parent && seq[h][1] == i))
					{
						break;
					}
				}
			}
			else if (map[minindex][i] != 0 && node[i].dis > map[minindex][i] + node[minindex].dis)
			{
				node[i].dis = map[minindex][i] + node[minindex].dis;
				node[i].parent = minindex;
			}

		}
	}

	for (int i = 0, j; i < n; i++)
	{
		if (i != start)
		{
			j = i;
			while (1)
			{
				if (node[j].dis == INF) 
				{
					stack[++top] = j;
					break;
				}
				if (node[j].parent == -1) break;
				stack[++top] = j;
				j = node[j].parent;
			}

			fprintf(out, "V0 ");
			for (k = top; k >= 0; k--) fprintf(out, "V%d ", stack[k]);
			if (node[i].dis != INF) fprintf(out, "(%d)\n", node[i].dis);
			else fprintf(out, "(-1)\n");
			memset(stack, 0, sizeof(int) * top);
			top = -1;
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}