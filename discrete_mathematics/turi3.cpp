#include <stdio.h>
#pragma warning (disable : 4996)

int pre[10000];
int in[10000];
int post[10000];
int visit[1000000];

int length_L(int pivot) {	//중위배열에서 왼쪽 길이 반환
	int cnt = 0;

	for (int i = pivot - 1; i >= 0; i--) {
		if (visit[in[i]] == 1) break;
		cnt++;
	}

	return cnt;
}

int length_R(int pivot, int length) {	//중위배열에서 오른쪽 길이 반환
	int cnt = 0;

	for (int i = pivot + 1; i < length; i++) {
		if (visit[in[i]] == 1) break;
		cnt++;
	}

	return cnt;
}

void post_order(int root, int pivot, int length, FILE *out) {	//루트는 값, 피봇은 위치
	visit[root] = 1;
	int left = length_L(pivot);
	int right = length_R(pivot, length);		//중위배열 정보로 찾는다

	int point;	//전위배열에서 루트의 위치
	for (int i = 0; i < length; i++) {
		if (pre[i] == root) { point = i; break; }
	}

	if (left == 0) {
		int point2;	//중위배열에서 왼쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == pre[point + 1]) { point2 = i; break; }
		}

		post_order(pre[point + 1], point2, length, out);
	}

	if (right == 0) {
		int point3;	//중위배열에서 오른쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == pre[point + left + 1]) { point3 = i; break; }
		}

		post_order(pre[point + left + 1], point3, length, out);
	}

	fprintf(out, "%d\n", root);
}

void pre_order(int root, int pivot, int length, FILE *out) {
	visit[root] = 1;
	int left = length_L(pivot);
	int right = length_R(pivot, length);		//중위배열 정보로 찾는다

	int point;	//전위배열에서 루트의 위치
	for (int i = 0; i < length; i++) {
		if (post[i] == root) { point = i; break; }
	}

	fprintf(out, "%d\n", root);

	if (left == 0) {
		int point2;	//중위배열에서 왼쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == post[point - right - 1]) { point2 = i; break; }
		}

		pre_order(post[point - right - 1], point2, length, out);
	}

	if (right == 0) {
		int point3;	//중위배열에서 오른쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == post[point - 1]) { point3 = i; break; }
		}

		pre_order(post[point - 1], point3, length, out);
	}
}

void find_root(int length, int &root, int &pivot, int type, int type2) {
	if (type + type2 < 0) {	//중위, 전위
		for (int i = 0; i < length; i++) {
			if (in[i] == pre[0]) {	//루트 값과 위치
				root = in[i];
				pivot = i;
				break;
			}
		}
	}
	else {	//중위, 후위
		for (int i = 0; i < length; i++) {
			if (in[i] == post[length - 1]) {	//루트 값과 위치
				root = in[i];
				pivot = i;
				break;
			}
		}
	}
}

int main() {
	FILE *inp = fopen("tree3.inp", "rt");
	FILE *out = fopen("tree3.out", "wt");

	int n, k, k2, root = 0, pivot = 0;

	fscanf(inp, "%d", &n);

	fscanf(inp, "%d", &k);
	if (k == -1) {
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &pre[i]);
	}
	else if (k == 0) {
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &in[i]);
	}
	else {
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &post[i]);
	}

	fscanf(inp, "%d", &k2);
	if (k2 == -1) {
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &pre[i]);
	}
	else if (k2 == 0) {
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &in[i]);
	}
	else {
		for (int i = 0; i < n; i++) fscanf(inp, "%d", &post[i]);
	}

	find_root(n, root, pivot, k, k2);

	if (k + k2 < 0) post_order(root, pivot, n, out);
	else pre_order(root, pivot, n, out);

	fclose(inp);
	fclose(out);
	return 0;
}