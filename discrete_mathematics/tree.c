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

int isItTree(int p[], int c[], int length) {//p는 부모노드들 c는 자식노드들 배열
	int tmp[2] = { 0 };	//tmp에 루트를 저장함 (루트가 두 개 이상 들어오면 걍 트리 탈락
	qsort(c, length , sizeof(int), compare);	//정렬
	for (int i = 0; i < length - 1; i++) { if (c[i] == c[i + 1]) return -1; }	//자식에 똑같은 자식이 있다 == 사이클 => 트리 탈락

	qsort(p, length, sizeof(int), compare);	//정렬
	for (int i = 0, j = 0; i < length; i++) {	//j는 tmp인덱스
		if (p[i] == p[i + 1] && i < length - 1) continue;		//부모로 입력 받은 것들 겹치는거 바로 넘김
		if (!bsearch(&p[i], c, length, sizeof(int), compare)) { tmp[j] = p[i]; j++; }		//p에 있는 것이 c배열 안에 있다면 그 놈은 루트가 아님
	}

	if (tmp[1] != 0) return -1;		//tmp 1번 인덱스에 0이 아닌 뭔가가 있다는건 루트가 두개
	else if (tmp[0] == 0) return -1;	//tmp 0번 인덱스가 0이면 루트가 없는 것 (사이클 같은 경우)
	else return tmp[0];				//tmp 1번에 아무것도 없고 0번에 뭔가가 있으면 그 놈이 루트
}

int main() {
	FILE *inp = fopen("tree.inp", "rt");
	FILE *out = fopen("tree.out", "wt");

	int parent[1000000], child[1000000];

	for (int i = 0, j = 1;; i++) {
		fscanf(inp, "%d %d", &parent[i], &child[i]);

		if (parent[i] == -1 && child[i] == -1) break;		//종료
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

int nodeCheck(int node, int node2) {	//노드 유무
	int check = 0;
	for (int i = 0; i < index; i++) {
		if (board[i].item == node) check++;
		if (board[i].item == node2) check += 2;
	}

	return check;	//0: 둘다 없다, 1: node만 있다, 2 :node2만 있다, 3: 둘다 있다
}

void edge(int node, int node2) {	//간선 긋기
	int check = nodeCheck(node, node2);

	if (check == 0) {	//둘다 없다
		board[index++].item = node;
		board[index].item = node2;
		board[index++].get++;
	}
	else if (check == 1) {	//node만 있다
		board[index].item = node2;
		board[index++].get++;
	}
	else if (check == 2) {	//node2만 있다
		board[index++].item = node;
		for (int i = 0; i < index; i++) {
			if (board[i].item == node2) {
				board[i].get++;
				break;
			}
		}
	}
	else {	//둘다 있다
		for (int i = 0; i < index; i++) {
			if (board[i].item == node2) {
				board[i].get++;
				break;
			}
		}
	}
}

int root() {	//루트 찾기
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