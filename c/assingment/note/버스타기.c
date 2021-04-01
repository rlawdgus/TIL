#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int Answer;
typedef struct Node {
	int data;
	struct Node *link;
	struct Node *next;
}Node;
Node *createNode(int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	newNode->next = NULL;

	return newNode;
}
void insertLink(Node *head, int data) {
	if (head == NULL) return;

	Node *newNode = createNode(data);
	Node *p = head;
	while (p->link != NULL) p = p->link;
	p->link = newNode;
}
void insertNext(Node *head, int data) {
	if (head == NULL) return;

	Node *newNode = createNode(data);
	Node *p = head;
	while (p->next != NULL) p = p->next;
	p->next = newNode;
}
int cntLink(Node *head) {
	if (head == NULL) return 0;

	int cnt = 0;
	Node *p = head;
	while (p->link != NULL) {
		cnt++;
		p = p->link;
	}

	return cnt + 1;
}
int cntNext(Node *head) {
	if (head == NULL) return 0;

	int cnt = 0;
	Node *p = head;
	while (p->next != NULL) {
		cnt++;
		p = p->next;
	}

	return cnt + 1;
}
int value(int data) {
	if (data < 0) data *= -1;
	return data;
}
int compareK(Node *head, int K, int data) {
	if (head == NULL) return 0;

	Node *p = head;
	while (p->link != NULL) {
		if (value(p->data - data) < K) return 1;
		p = p->link;
	}
	if (value(p->data - data) < K) return 1;
	else return 0;
}

int main(void) {
	Node *board = createNode(0);
	int T, test_case;
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++) {
		int N, K, tmp;
		scanf("%d %d", &N, &K);
		int *ability = (int *)malloc(sizeof(int) * N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &ability[i]);
			if (N == 1) { Answer = 1; break; }
			if (!i) board->data = ability[i];
			else {
				tmp = compareK(board, K, value(ability[i] - ability[i - 1]));
				if (tmp) insertNext(board, ability[i]);
				else insertLink(board, ability[i]);
			}
			tmp = 0;
		}

		if (cntLink(board) < cntNext(board)) Answer = cntLink(board);
		else Answer = cntNext(board);

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
		Answer = 0;
	}

	free(board);
	return 0;
}