#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}Node;

Node *tree_ll(Node *p) {
	Node *child;

	child = p->left;
	p->left = child->right;
	child->right = p;
	return child;
}

Node *tree_rr(Node *p) {
	Node *child;

	child = p->right;
	p->right = child->left;
	child->left = p;
	return child;
}

Node *tree_lr(Node *p) {
	Node *child;

	child = p->left;
	p->left = tree_rr(child);
	return tree_ll(p);
}

Node *tree_rl(Node *p) {
	Node *child;

	child = p->right;
	p->right = tree_ll(child);
	return tree_rr(p);
}

int get_height(Node *node) {
	int height;

	height = 0;
	if (node != NULL) {
		int tmp = get_height(node->left);
		int tmp2 = get_height(node->right);
		height = tmp > tmp2 ? tmp : tmp2;
		height++;
	}
	return height;
}

int get_balance(Node *node) {
	if (node == NULL) return 0;
	return get_height(node->left) - get_height(node->right);
}

Node *balancing(Node *node) {
	int height;

	height = get_balance(node);
	if (height > 1) {
		if (get_balance(node->left) > 0) {
			printf("LL\n");
			node = tree_ll(node);
		}
		else {
			printf("LR\n");
			node = tree_lr(node);
		}
	}
	else if (height < -1) {
		if (get_balance(node->right) < 0) {
			printf("RR\n");
			node = tree_rr(node);
		}
		else {
			printf("RL\n");
			node = tree_rl(node);
		}
	}
	return node;
}

Node *insertNode(Node *root, int data) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		if (root == NULL) {
			perror("메모리 할당 실패 \n");
			exit(-1);
		}
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (root->data > data) {
		root->left = insertNode(root->left, data);
		root = balancing(root);
	}
	else if (root->data < data) {
		root->right = insertNode(root->right, data);
		root = balancing(root);
	}
	else printf("중복된 data로 인하여 삽입 실패 \n");

	return root;
}

Node *deleteNode(Node *root, Node *tmp, int key) {
	if (key < root->data) root->left = deleteNode(root->left, tmp, key);
	else if (key > root->data) root->right = deleteNode(root->right, tmp, key);
	else {
		Node *parent, *p, *succ, *succ_p;
		Node *child;

		parent = tmp;
		p = root;

		if ((p->left == NULL) && (p->right == NULL)) {	//삭제할 노드가 단말 노드인 경우
			if (parent != NULL) {
				if (parent->left == p) parent->left = NULL;
				else parent->right = NULL;
				printf("단말노드 삭제\n");
				return parent;
			}
			else return NULL;
		}
		else if ((p->left == NULL) || (p->right == NULL)) {	//삭제할 노드가 한 개의 자식 노드를 가진 경우
			if (p->left != NULL) child = p->left;
			else child = p->right;

			if (parent != NULL) {
				if (parent->left == p) parent->left = child;
				else parent->right = child;
				return parent;
			}
			else return child;
		}
		else {	//삭제할 노드가 두 개의 자식 노드를 가진 경우
			succ_p = p;
			succ = p->left;
			while (succ->right != NULL) {
				succ_p = succ;
				succ = succ->right;
			}
			if (succ_p->left == succ) succ_p->left = succ->left;
			else succ_p->right = succ->left;
			p->data = succ->data;
			p = succ;

			free(p);
		}
	}

	return balancing(root);
}

void pre_order(Node *root, FILE *out) {  //전위 순회로 구현
	if (root == NULL) return;

	fprintf(out, "%d ", root->data);
	pre_order(root->left, out);
	pre_order(root->right, out);
}

int main() {
	FILE *inp = fopen("hw4.inp", "rt");
	FILE *out = fopen("hw4.out", "wt");

	if (inp == NULL) return 0;

	int num; char ch; Node *root = NULL;

	while (1) {	//삽입
		fscanf(inp, "%d", &num);
		root = insertNode(root, num);

		ch = fgetc(inp);
		if (ch == '\n') break;
	}

	pre_order(root, out);
	fprintf(out, "\n");

	while (1) {	//삭제
		fscanf(inp, "%d", &num);
		root = deleteNode(root, NULL, num);

		ch = fgetc(inp);
		if (ch == '\n') break;
	}

	pre_order(root, out);
	fprintf(out, "\n*");

	fclose(inp);
	fclose(out);
	return 0;
}