#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int cnt = 1, cnt2 = 0;

typedef struct Node {
	struct Node *child[10];
	char key[4];
	int num;
}Node;

Node *createNode() {
	Node *newNode = (Node *)malloc(sizeof(Node));

	for (int i = 0; i < 10; i++) newNode->child[i] = NULL;
	for (int i = 0; i < 4; i++) newNode->key[i] = NULL;
	newNode->num = 0;

	return newNode;
}

void insertNode(Node *tri, char index[], int index_num, char key[]) {
	if (index_num == 4) {
		for (int i = 0; i < 4; i++) tri->key[i] = key[i];
		return;
	}

	if (tri->child[index[index_num] - 48] == NULL) { tri->child[index[index_num] - 48] = createNode(); cnt++; }
	insertNode(tri->child[index[index_num] - 48], index, index_num + 1, key);
}

void DFS(Node *tri, char input[], char tmp[], int index, FILE *out) {
	if (index == 4) {
		for (int i = 0; i < 4; i++) fprintf(out, "%c", tmp[i]);
		fprintf(out, " %d ", tri->num);
		for (int i = 0; i < 4; i++) fprintf(out, "%c", tri->key[i]);
		fprintf(out, " ");
		return;
	}

	if (index == 3) {
		for (int i = 0, j = 1; i < 10; i++) {
			if (tri->child[i] != NULL) {
				tri->child[i]->num = j++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (tri->child[i] != NULL) {
			tmp[index] = i + 48;
			if (tri->child[i] == NULL) { fprintf(out, "no\n"); return; }
			DFS(tri->child[i], input, tmp, index + 1, out);
		}
	}
}

void wild_card(Node *tri, char input[], int wc, int index, char tmp[], FILE *out) {
	if (index == wc) {
		DFS(tri, input, tmp, index, out);
		fprintf(out, "\n");
		return;
	}

	tmp[index] = input[index];
	if (tri->child[input[index] - 48] == NULL) { fprintf(out, "no\n"); return; }
	wild_card(tri->child[input[index] - 48], input, wc, index + 1, tmp, out);
}

void find_key(Node *tri, char input[], int index, char tmp[],  FILE *out, int position) {
	if (index == 4) {	//리프노드 도달
		for (int i = 0; i < 4; i++) fprintf(out, "%c", tmp[i]);
		fprintf(out, " %d ", position);
		for (int i = 0; i < 4; i++) fprintf(out, "%c", tri->key[i]);
		fprintf(out, "\n");
		return;
	}

	if (index == 3) {
		for (int i = 0; i < 10; i++) {
			if (tri->child[i] != NULL) position++;
			if (i == (input[index] - 48)) break;
		}
	}

	tmp[index] = input[index];
	if (tri->child[input[index] - 48] == NULL) { fprintf(out, "no\n"); return; }	//자식 노드가 없는 경우
	find_key(tri->child[input[index] - 48], input, index + 1, tmp, out, position);
}

int main() {
	FILE *inp = fopen("hw4.inp", "rt");
	FILE *out = fopen("hw4.out", "wt");

	if ((inp = fopen("hw4.inp", "rt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw4.inp");

	if ((out = fopen("hw4.out", "wt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw4.out");

	char index[4], key[4], ch;
	Node *tri = createNode();

	while (1) {	//입력
		for (int i = 0, j = 0, k = 0; i < 11; i++) {
			if (i == 0 || i == 5 || i == 10) ch = fgetc(inp);
			else if (i < 5) fscanf(inp, "%c", &index[j++]);
			else fscanf(inp, "%c", &key[k++]);
		}
	
		insertNode(tri, index, 0, key);
		cnt2++;

		ch = fgetc(inp);
		if (ch == '\n') break;
	}
	fprintf(out, "%d\n", cnt - cnt2);

	char input[4], tmp[4] = { 0 };
	int i = 0;

	while (1) {
		ch = fgetc(inp);
		if (ch == '\n') { fprintf(out, "*"); break; }
		if (ch == ' ') ch = fgetc(inp);
		if (ch == '\n') { fprintf(out, "*"); break; }

		input[i++] = ch;
		
		if (ch == '*') {
			wild_card(tri, input, i - 1, 0, tmp, out);
			i = 0;
		}

		else if (i == 4) {
			find_key(tri, input, 0, tmp, out, 0);
			i = 0;
		}


		//ch = fgetc(inp);
		//input[i++] = ch;
		//if (ch == '\n') { fprintf(out, "*"); break; }

		//if (ch == '*') {
		//	wild_card(tri, input, i - 1, 0, tmp, out);
		//	i = 0;
		//	ch = fgetc(inp);
		//}

		//else if (i == 4) {
		//	find_key(tri, input, 0, tmp, out, 0);
		//	i = 0;
		//	ch = fgetc(inp);
		//}
	}

	fclose(inp);
	fclose(out);
	return 0;
}