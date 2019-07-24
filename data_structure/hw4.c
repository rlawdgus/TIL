#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
}Node;
Node *insert(Node *tree, int key) {
	if (tree == NULL) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->key = key;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if (key < tree->key) tree->right = insert(tree->right, key);
	else if (key > tree->key) tree->left = insert(tree->left, key);

	return tree;
}
void preOrder(Node *tree, FILE *out) {
	if (tree != NULL) {
		fprintf(out, "%d ", tree->key);
		preOrder(tree->left, out);
		preOrder(tree->right, out);
	}
}
void del(Node *tree, int key) {
	Node *parent = NULL, *child, *p = tree, *succ, *succ_parent, *succ2, *succ2_parent;
	while (p != NULL && p->key != key) {
		parent = p;
		if (key < p->key) p = p->right;
		else p = p->left;
	}
	if (p == NULL) return;
	if (p->left == NULL && p->right == NULL) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else tree = NULL;
	}
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else {
			p->key = child->key;
			p->left = child->left;
			p->right = child->right;
			free(child);
			return;
		}
	}
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		succ2_parent = p;
		succ2 = p->right;
		while (succ2->left != NULL) {
			succ2_parent = succ2;
			succ2 = succ2->left;
		}
		if (succ->key - p->key <= p->key - succ2->key) {
			if (succ_parent->left == succ) succ_parent->left = succ->left;
			else succ->right = succ->left;
			p->key = succ->key;
			p = succ;
			p = NULL;
		}
		else {
			if (succ2_parent->right == succ2) succ2_parent->right = succ2->right;
			else succ2_parent->left = succ2->right;
			p = succ2;
			p = NULL;
		}
	}
	free(p);
}
void search(Node *tree, int key, FILE *out) {
	if (tree == NULL) return;
	Node *ptr = tree;
	while (1) {
		if (ptr == NULL) break;
		if (key == ptr->key) {
			fprintf(out, "%d\n", ptr->key);
			fprintf(out, "Yes\n");
			fprintf(out, "*");
			return;
		}
		else if (key < ptr->key) {
			if (ptr->left == NULL && ptr->right == NULL) {
				fprintf(out, "%d ", ptr->key);
				break;
			}
			fprintf(out, "%d ", ptr->key);
			ptr = ptr->right;
		}
		else {
			if (ptr->left == NULL && ptr->right == NULL) {
				fprintf(out, "%d", ptr->key);
				break;
			}
			fprintf(out, "%d ", ptr->key);
			ptr = ptr->left;
		}
	}
	fprintf(out, "\n");
	fprintf(out, "No\n");
	fprintf(out, "*");
	return;
}

int main() {
	FILE *inp = fopen("hw4.inp", "rt");
	FILE *out = fopen("hw4.out", "wt");

	Node *tree = NULL;
	int num = 0;
	char ch = 0;

	fscanf(inp, "%d", &num);
	fscanf(inp, "%c", &ch);
	tree = insert(tree, num);
	while (1) {
		fscanf(inp, "%d", &num);
		fscanf(inp, "%c", &ch);
		insert(tree, num);
		if (ch == '\n') break;
	}
	preOrder(tree, out);
	fprintf(out, "\n");

	while (1) {
		fscanf(inp, "%d", &num);
		fscanf(inp, "%c", &ch);
		del(tree, num);
		if (ch == '\n') break;
	}
	preOrder(tree, out);
	fprintf(out, "\n");

	fscanf(inp, "%d", &num);
	search(tree, num, out);

	fclose(inp);
	fclose(out);
	return 0;
}