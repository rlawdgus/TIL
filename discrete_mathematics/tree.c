#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int isItTree(int p[], int c[], int length) {//p�� �θ���� c�� �ڽĳ��� �迭
	int tmp[2] = { 0 };	//tmp�� ��Ʈ�� ������ (��Ʈ�� �� �� �̻� ������ �� Ʈ�� Ż��
	qsort(c, length , sizeof(int), compare);	//����
	for (int i = 0; i < length - 1; i++) { if (c[i] == c[i + 1]) return -1; }	//�ڽĿ� �Ȱ��� �ڽ��� �ִ� == ����Ŭ => Ʈ�� Ż��

	qsort(p, length, sizeof(int), compare);	//����
	for (int i = 0, j = 0; i < length; i++) {	//j�� tmp�ε���
		if (p[i] == p[i + 1] && i < length - 1) continue;		//�θ�� �Է� ���� �͵� ��ġ�°� �ٷ� �ѱ�
		if (!bsearch(&p[i], c, length, sizeof(int), compare)) { tmp[j] = p[i]; j++; }		//p�� �ִ� ���� c�迭 �ȿ� �ִٸ� �� ���� ��Ʈ�� �ƴ�
	}

	if (tmp[1] != 0) return -1;		//tmp 1�� �ε����� 0�� �ƴ� ������ �ִٴ°� ��Ʈ�� �ΰ�
	else if (tmp[0] == 0) return -1;	//tmp 0�� �ε����� 0�̸� ��Ʈ�� ���� �� (����Ŭ ���� ���)
	else return tmp[0];				//tmp 1���� �ƹ��͵� ���� 0���� ������ ������ �� ���� ��Ʈ
}

int main() {
	FILE *inp = fopen("tree.inp", "rt");
	FILE *out = fopen("tree.out", "wt");

	int parent[1000000], child[1000000];

	for (int i = 0, j = 1;; i++) {
		fscanf(inp, "%d %d", &parent[i], &child[i]);

		if (parent[i] == -1 && child[i] == -1) break;		//����
		if (parent[i] == 0 && child[i] == 0) {
			fprintf(out, "Test Case %d: %d\n", j++, isItTree(parent, child, i));
			i = -1;
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}

/*
typedef struct Node {
	int item;
	int get;
}Node;

Node board[1000000];
int index;

int nodeCheck(int node, int node2) {	//��� ����
	int check = 0;
	for (int i = 0; i < index; i++) {
		if (board[i].item == node) check++;
		if (board[i].item == node2) check += 2;
	}

	return check;	//0: �Ѵ� ����, 1: node�� �ִ�, 2 :node2�� �ִ�, 3: �Ѵ� �ִ�
}

void edge(int node, int node2) {	//���� �߱�
	int check = nodeCheck(node, node2);

	if (check == 0) {	//�Ѵ� ����
		board[index++].item = node;
		board[index].item = node2;
		board[index++].get++;
	}
	else if (check == 1) {	//node�� �ִ�
		board[index].item = node2;
		board[index++].get++;
	}
	else if (check == 2) {	//node2�� �ִ�
		board[index++].item = node;
		for (int i = 0; i < index; i++) {
			if (board[i].item == node2) {
				board[i].get++;
				break;
			}
		}
	}
	else {	//�Ѵ� �ִ�
		for (int i = 0; i < index; i++) {
			if (board[i].item == node2) {
				board[i].get++;
				break;
			}
		}
	}
}

int root() {	//��Ʈ ã��
	for (int i = 0; i < index; i++) if (board[i].get == 0) return board[i].item;
}

int isItTree() {
	int edge = 0;
	for (int i = 0; i < index; i++) {
		if (board[i].get > 1) return -1;
		if (board[i].get == 0) continue;
		edge++;
	}

	if (edge + 1 != index) return -1;
	return root();
}

int main() {
	FILE *inp = fopen("tree.inp", "rt");
	FILE *out = fopen("tree.out", "wt");

	int T = 1, start, dest;
	while (T) {
		fscanf(inp, "%d %d", &start, &dest);

		if (start == -1 && dest == -1) break;
		else if (start == 0 && dest == 0) {
			fprintf(out, "Test Case %d: %d\n", T, isItTree());
			for (int i = 0; i < index; i++) { board[i].item = 0; board[i].get = 0; }
			index = 0;
			T++;
		}
		else edge(start, dest);
	}
	
	fclose(inp);
	fclose(out);
	return 0;
}*/