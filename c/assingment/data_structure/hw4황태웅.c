#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct Node   //��� ����ü
{
	int key;
	struct Node *left;
	struct Node *right;
}Node;

typedef struct Tree1      //��Ʈ �����
{
	Node *root;
}Tree1;

Node *CreateNode(int key)       //������
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void Insertkey1(Tree1 *tree, int key)
{
	Node *ptr = tree->root;
	Node *pre = NULL;

	while (ptr != NULL)           //������ ��� Ž��
	{
		if (ptr->key == key)
			return;
		pre = ptr;
		if (key > ptr->key)
			ptr = ptr->left;
		else if (key < ptr->key)
			ptr = ptr->right;
	}

Node *newNode = CreateNode(key);      //������ ��� ����

	if (tree->root == NULL)      //��� ����
		tree->root = newNode;
	else if (key > pre->key)
		pre->left = newNode;
	else if (key < pre->key)
		pre->right = newNode;
	return;
}

void Search2(Node *tree, int key, FILE *output)          //�ݺ������� Ž������ ���� �� ������ ����1 ������ ����0
{
	Node *p = tree;
	while (p != NULL)
	{
		if (p->key == key)
		{
			fprintf(output, "%d\n", p->key);
			fprintf(output, "Yes");
			return;
		}
		else if (p->key < key)
		{
			fprintf(output, "%d ", p->key);
			p = p->left;
		}
		else
		{
			fprintf(output, "%d ", p->key);
			p = p->right;
		}
	}
	fprintf(output, "\n");
	fprintf(output, "No");
}


void Del1(Tree1 *tree, int key)          //��������
{
	Node *ptr = tree->root; //root
	Node *pre = NULL; // parent
	Node *parent1 = ptr;  // ���� 
	Node *child1 = ptr->left; // �����İ���
	Node *parent2 = ptr; //������
	Node *child2 = ptr->right; //�������İ���

	int num = 0;


	while (1)         //�����Ұ� Ž��
	{
		if (ptr == NULL)
			return;
		if (ptr->key == key)
			break;
		else if (ptr->key < key)
		{
			pre = ptr;
			ptr = ptr->left;
			num = 1;
			continue;
		}
		else
		{
			pre = ptr;
			ptr = ptr->right;
			num = 1;
			continue;
		}
	}

 // �ΰ�����Ʈ��
	if (ptr->left != NULL && ptr->right != NULL)
	{
		parent1 = ptr;  // ���� 
		child1 = ptr->left; // �����İ���
		while (child1->right != NULL)
		{
			parent1 = child1;
			child1 = child1->right;
		}
		int hubo1 = child1->key;
		parent2 = ptr; 
		child2 = ptr->right; 
		while (child2->left != NULL)
		{
			parent2 = child2;
			child2 = child2->left;
		}
		int hubo2 = child2->key;


		if (hubo1 - ptr->key > ptr->key - hubo2)
		{
			if (ptr->right == child2) {
				ptr->right = child2->right;
			}
			else {
				ptr->right = child2->left;
				//ptr->left = NULL;
			}
			ptr->key = child2->key;
			ptr = child2;
		}
		else
		{
			if (ptr->left == child1) {
				ptr->left = child1;
			}
			else {
				ptr->left = child1->right;
				//ptr->right = NULL;
			}
			ptr->key = child1->key;
			ptr=child1;
		}
		free(ptr);
	}
	else if (ptr->left != NULL)                //���� �ڽĸ� �ִ� ���
	{
		if (pre == NULL)
		{
			pre = ptr;
			ptr = ptr->left;
			tree->root = ptr;
			free(pre);
		}
		else
		{
			if (pre->left == ptr)
			{
				pre->left = ptr->left;            //�θ��� ���ʿ� �ڽ��� �̾������
				free(ptr);
			}
			else if (pre->right == ptr)             //�θ��� �����ʿ� �ڽ��� �̾������
			{
				pre->right = ptr->left;
				free(ptr);
			}
		}
	}
	else if (ptr->right != NULL)              //������ �ڽĸ� �ִ� ���
	{
		if (pre == NULL)
		{
			pre = ptr;
			ptr = ptr->right;
			tree->root = ptr;
			free(pre);
		}
		else
		{
			if (pre->left == ptr)
			{
				pre->left = ptr->right;          //�θ��� ���ʿ� �ڽ��� �̾������
				free(ptr);
			}
			else if (pre->right == ptr)
			{
				pre->right = ptr->right;         //�θ��� �����ʿ� �ڽ��� �̾������

				free(ptr);
			}
		}
	}
	else              //�ڽ��� ���°��(�ܸ����)
	{
		if (pre->left == ptr)
		{
			pre->left = NULL;
			free(ptr);
		}
		else
		{
			pre->right = NULL;
			free(ptr);
		}
	}
}

int preorder(Node *node, FILE *output)    //������ȸ
{
	if (node != NULL)
	{
		fprintf(output, "%d ", node->key);
		preorder(node->left, output);
		preorder(node->right, output);
	}
}

int main()
{
	FILE *input = fopen("hw4.inp", "rt");
	FILE *output = fopen("hw4.out", "wt");

	Tree1 *tree = (Tree1*)malloc(sizeof(Tree1));
	tree->root = NULL;
	int num;
	char enter;

	while (1)            //ù°�� ������ȸ
	{
		fscanf(input, "%d", &num);
		fscanf(input, "%c", &enter);
		Insertkey1(tree, num);
		if (enter == '\n')
			break;
	}
	preorder(tree->root, output);
	fprintf(output, "\n");

	while (1)       //�ι�°�� ���� �� ������ȸ
	{
		fscanf(input, "%d", &num);
		fscanf(input, "%c", &enter);
		Del1(tree, num);
		if (enter == '\n')
			break;
	}
	preorder(tree->root, output);
	fprintf(output, "\n");

	fscanf(input, "%d", &num);
	Search2(tree->root, num, output);
	fprintf(output, "\n");

	fprintf(output, "*");


	return 0;
}