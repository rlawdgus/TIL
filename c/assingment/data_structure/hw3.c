#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	char ch;
	struct Node *next;
}Node;
Node *createNode(char ch) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->ch = ch;
	newNode->next = NULL;
	return newNode;
}
void push(Node *head, char ch) {
	Node *newNode = createNode(ch);
	newNode->next = head->next;
	head->next = newNode;
}
void pop(Node *head, FILE *out) {
	if (head->next == NULL) return;
	Node *p = head->next;
	fprintf(out, "%c", p->ch);
	head->next = head->next->next;
	free(p);
}
void enqueue(Node *head, char ch) {
	Node *newNode = createNode(ch);
	if (head->next == NULL) {
		newNode->next = head->next;
		head->next = newNode;
	}
	else {
		Node *p = head->next;
		while (p->next != NULL) p = p->next;
		p->next = newNode;
	}
}
int length(Node *head) {
	if (head->next == NULL) return 0;
	int num = 1;
	Node *p = head->next;
	while (p->next != NULL) {
		p = p->next;
		num++;
	}

	return num;
}

int main() {
	FILE *inp = fopen("hw3.inp", "rt");
	FILE *out = fopen("hw3.out", "wt");

	Node *stack = createNode('S');
	Node *queue = createNode('Q');
	char ch = 0;

	while (1) {
		ch = fgetc(inp);
		if (ch == '\n') break;
		push(stack, ch);
	}
	while (stack->next != NULL) pop(stack, out);
	ch = 0;
	fprintf(out, "\n");



	while (1) {
		ch = fgetc(inp);
		if (ch == '\n') break;
		enqueue(queue, ch);
	}
	ch = 0;

	Node *key = createNode('K');
	while (1) {
		ch = fgetc(inp);
		if (ch == '\n') break;
		enqueue(key, ch - 48);
	}

	int len = length(key);
	int cnt = 0;
	int temp;
	Node *p = queue->next;
	while (p->next != NULL) {
		Node *q = key->next;
		if (p->ch == ' ') {
			p = p->next;
			fprintf(out, " ");
			continue;
		}
		else if (p->ch >= 97 && p->ch <= 122) {
			temp = cnt % len;
			for (int i = 0; i < temp; i++) q = q->next;
			if (p->ch - q->ch >= 97 && p->ch - q->ch <= 122)
				fprintf(out, "%c", p->ch - q->ch);
			else fprintf(out, "%c", p->ch - q->ch + 26);
			p = p->next;
			cnt++;
		}
		else if (p->ch - q->ch >= 65 && p->ch - q->ch <= 90) {
			temp = cnt % len;
			for (int i = 0; i < temp; i++) q = q->next;
			if (p->ch - q->ch >= 65 && p->ch - q->ch <= 90)
				fprintf(out, "%c", p->ch - q->ch);
			else fprintf(out, "%c", p->ch - q->ch + 26);
			p = p->next;
			cnt++;
		}
	}
	Node *q = key->next;
	if (p->ch == ' ') {
		p = p->next;
		fprintf(out, " ");
	}
	else if (p->ch >= 97 && p->ch <= 122) {
		temp = cnt % len;
		for (int i = 0; i < temp; i++) q = q->next;
		if (p->ch - q->ch >= 97 && p->ch - q->ch <= 122)
			fprintf(out, "%c", p->ch - q->ch);
		else fprintf(out, "%c", p->ch - q->ch + 26);
	}
	else if (p->ch - q->ch >= 65 && p->ch - q->ch <= 90) {
		temp = cnt % len;
		for (int i = 0; i < temp; i++) q = q->next;
		if (p->ch - q->ch >= 65 && p->ch - q->ch <= 90)
			fprintf(out, "%c", p->ch - q->ch);
		else fprintf(out, "%c", p->ch - q->ch + 26);
	}
	fprintf(out, "\n");
	fprintf(out, "*");

	fclose(inp);
	fclose(out);
	return 0;
}