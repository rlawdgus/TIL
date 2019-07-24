#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int coef;
	int expo;
	struct Node *link;
}Node;
Node *createNode(int coef, int expo) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;
	return newNode;
}

void addNode(Node *head, int coef, int expo) {
	Node *newNode = createNode(coef, expo);
	Node *p;

	if (head->link == NULL) {
		head->link = newNode;
		return;
	}
	else {
		p = head->link;
		while (p->link != NULL) p = p->link;
		p->link = newNode;
	}
}
void insertNode(Node *head, int coef, int expo) {
	Node *newNode = createNode(coef, expo);
	Node *p = head;

	if (head->link == NULL) {
		head->link = newNode;
		return;
	}

	while (p->link != NULL) {
		if (p->link->expo == expo)
			return;
		if (p->link->expo < expo) {
			newNode->link = p->link;
			p->link = newNode;
			return;
		}
		p = p->link;
	}
	p->link = newNode;
}

void deleteNode(Node *head, int expo) {
	Node *pre;
	Node *current;
	pre = head;
	current = head->link;

	if (head->link == NULL) return;

	while (current != NULL) {
		if (current->expo == expo) {
			pre->link = current->link;
			free(current);
			return;
		}
		pre = current;
		current = current->link;
	}
}

void sumPoly(Node *F, Node *G, Node *H) {
	Node *p = F->link;
	Node *q = G->link;
	int sum;

	while (p != NULL && q != NULL) {
		if (p->expo == q->expo) {
			sum = p->coef + q->coef;
			if(sum != 0) addNode(H, sum, p->expo);
			p = p->link;
			q = q->link;
		}
		else if (p->expo > q->expo) {
			addNode(H, p->coef, p->expo);
			p = p->link;
		}
		else {
			addNode(H, q->coef, q->expo);
			q = q->link;
		}
	}

	while (p != NULL) {
		addNode(H, p->coef, p->expo);
		p = p->link;
	}
	while (q != NULL) {
		addNode(H, q->coef, q->expo);
		q = q->link;
	}
}

void printList(Node *head1, Node *head2, Node *head3, FILE *out) {
	Node *p = head1->link;
	while (p != NULL) {
		fprintf(out, "%d %d ", p->coef, p->expo);
		p = p->link;
	}
	fprintf(out, "\n");

	p = head2->link;
	while (p != NULL) {
		fprintf(out, "%d %d ", p->coef, p->expo);
		p = p->link;
	}
	
	fprintf(out, "\n");

	p = head3->link;
	while (p != NULL) {
		fprintf(out, "%d %d ", p->coef, p->expo);
		p = p->link;
	}
	fprintf(out, "\n");
	fprintf(out, "*");
}

int main() {
	FILE *inp = fopen("hw2.inp", "rt");
	FILE *out = fopen("hw2.out", "wt");

	Node *f = createNode(0, 0);
	Node *g = createNode(0, 0);
	Node *h = createNode(0, 0);

	int temp1, temp2, count = 0;
	char ch = '\n';

	while (1) {
		if (fscanf(inp, "%d %d", &temp1, &temp2)) ch = fgetc(inp);
		else if (ch == '\n' || ch == ' ') break;
		addNode(f, temp1, temp2);
	}

	ch = fgetc(inp);
	
	if (ch == 'I') {
		while (1) {
			if (count % 2 == 0) fscanf(inp, "%d", &temp1);
			else {
				fscanf(inp, "%d", &temp2);
				insertNode(f, temp1, temp2);
			}

			fscanf(inp, "%c", &ch);
			if (ch == '\n') break;

			count++;
		}
	}
	else if (ch == 'D') {
		while (1) {
			fscanf(inp, "%d", &temp1);
			deleteNode(f, temp1);
			fscanf(inp, "%c", &ch);
			if (ch == '\n') break;
		}		
	}
	count = 0;

	while (1) {
		if(fscanf(inp, "%d %d", &temp1, &temp2)) ch = fgetc(inp);
		else if (ch == '\n' || ch == ' ') break;
		addNode(g, temp1, temp2);
	}

	ch = fgetc(inp);
	if (ch == 'I') {
		while (1) {
			if (count % 2 == 0) fscanf(inp, "%d", &temp1);
			else {
				fscanf(inp, "%d", &temp2);
				insertNode(g, temp1, temp2);
			}

			fscanf(inp, "%c", &ch);
			if (ch == '\n') break;

			count++;
		}
	}
	else if (ch == 'D') {
		while (1) {
			fscanf(inp, "%d", &temp1);
			deleteNode(g, temp1);
			fscanf(inp, "%c", &ch);
			if (ch == '\n') break;
		}
	}
	count = 0;
	

	sumPoly(f, g, h);
	printList(f, g, h, out);

	fclose(inp);
	fclose(out);
	return 0;
}