#include <fstream>
using namespace std;

ifstream inp("tree3.inp");
ofstream out("tree3.out");

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

void post_order(int root, int pivot, int length) {	//루트는 값, 피봇은 위치
	visit[root] = 1;
	int left = length_L(pivot);
	int right = length_R(pivot, length);		//중위배열 정보로 찾는다

	int point;	//전위배열에서 루트의 위치
	for (int i = 0; i < length; i++) {
		if (pre[i] == root) { point = i; break; }
	}

	if (left) {
		int point2;	//중위배열에서 왼쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == pre[point + 1]) { point2 = i; break; }
		}

		post_order(pre[point + 1], point2, length);
	}

	if (right) {
		int point3;	//중위배열에서 오른쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == pre[point + left + 1]) { point3 = i; break; }
		}

		post_order(pre[point + left + 1], point3, length);
	}

	out << root << '\n';
}

void pre_order(int root, int pivot, int length) {
	visit[root] = 1;
	int left = length_L(pivot);
	int right = length_R(pivot, length);		//중위배열 정보로 찾는다

	int point;	//전위배열에서 루트의 위치
	for (int i = 0; i < length; i++) {
		if (post[i] == root) { point = i; break; }
	}

	out << root << '\n';

	if (left) {
		int point2;	//중위배열에서 왼쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == post[point - right - 1]) { point2 = i; break; }
		}

		pre_order(post[point - right - 1], point2, length);
	}

	if (right) {
		int point3;	//중위배열에서 오른쪽 서브트리 루트의 위치
		for (int i = 0; i < length; i++) {
			if (in[i] == post[point - 1]) { point3 = i; break; }
		}

		pre_order(post[point - 1], point3, length);
	}
}

void traversal(int length, int k[]) {
	int root, pivot;

	if (k[0] + k[1] < 0) {	//중위, 전위
		for (int i = 0; i < length; i++) {
			if (in[i] == pre[0]) {	//루트 값과 위치
				root = in[i];
				pivot = i;
				break;
			}
		}
		post_order(root, pivot, length);
	}
	else {	//중위, 후위
		for (int i = 0; i < length; i++) {
			if (in[i] == post[length - 1]) {	//루트 값과 위치
				root = in[i];
				pivot = i;
				break;
			}
		}
		pre_order(root, pivot, length);
	}
}

void input(int n, int k) {
	if (k == -1) {
		for (int i = 0; i < n; i++) inp >> pre[i];
	}
	else if (k == 0) {
		for (int i = 0; i < n; i++) inp >> in[i];
	}
	else {
		for (int i = 0; i < n; i++) inp >> post[i];
	}
}

int main() {
	int n, k[2];

	inp >> n;

	inp >> k[0];
	input(n, k[0]);

	inp >> k[1];
	input(n, k[1]);

	traversal(n, k);

	inp.close();
	out.close();
	return 0;
}