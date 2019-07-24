#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct Node   //노드 구조체
{
	int key;
	struct Node *left;
	struct Node *right;
}Node;

typedef struct Tree1      //루트 만들기
{
	Node *root;
}Tree1;

Node *CreateNode(int key)       //노드생성
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

	while (ptr != NULL)           //삽입할 노드 탐색
	{
		if (ptr->key == key)
			return;
		pre = ptr;
		if (key > ptr->key)
			ptr = ptr->left;
		else if (key < ptr->key)
			ptr = ptr->right;
	}

Node *newNode = CreateNode(key);      //삽입할 노드 생성

	if (tree->root == NULL)      //노드 연결
		tree->root = newNode;
	else if (key > pre->key)
		pre->left = newNode;
	else if (key < pre->key)
		pre->right = newNode;
	return;
}

void Search2(Node *tree, int key, FILE *output)          //반복문으로 탐색연산 수행 후 있으면 리턴1 없으면 리턴0
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


void Del1(Tree1 *tree, int key)          //삭제연산
{
	Node *ptr = tree->root; //root
	Node *pre = NULL; // parent
	Node *parent1 = ptr;  // 왼쪽 
	Node *child1 = ptr->left; // 왼쪽후계자
	Node *parent2 = ptr; //오른쪽
	Node *child2 = ptr->right; //오른쪽후계자

	int num = 0;


	while (1)         //삭제할거 탐색
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

 // 두개서브트리
	if (ptr->left != NULL && ptr->right != NULL)
	{
		parent1 = ptr;  // 왼쪽 
		child1 = ptr->left; // 왼쪽후계자
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
	else if (ptr->left != NULL)                //왼쪽 자식만 있는 경우
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
				pre->left = ptr->left;            //부모의 왼쪽에 자식을 이어붙히기
				free(ptr);
			}
			else if (pre->right == ptr)             //부모의 오른쪽에 자식을 이어붙히기
			{
				pre->right = ptr->left;
				free(ptr);
			}
		}
	}
	else if (ptr->right != NULL)              //오른쪽 자식만 있는 경우
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
				pre->left = ptr->right;          //부모의 왼쪽에 자식을 이어붙히기
				free(ptr);
			}
			else if (pre->right == ptr)
			{
				pre->right = ptr->right;         //부모의 오른쪽에 자식을 이어붙히기

				free(ptr);
			}
		}
	}
	else              //자식이 없는경우(단말노드)
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

int preorder(Node *node, FILE *output)    //전위순회
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

	while (1)            //첫째줄 전위순회
	{
		fscanf(input, "%d", &num);
		fscanf(input, "%c", &enter);
		Insertkey1(tree, num);
		if (enter == '\n')
			break;
	}
	preorder(tree->root, output);
	fprintf(output, "\n");

	while (1)       //두번째줄 삭제 후 전위순회
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