#include <fstream>
#include <algorithm>
using namespace std;

int isItTree(int p[], int c[], int length) {//p�� �θ���� c�� �ڽĳ��� �迭
	int tmp[2] = { 0 };	//tmp�� ��Ʈ�� ������ (��Ʈ�� �� �� �̻� ������ �� Ʈ�� Ż��
	sort(c, c + length);	//����
	for (int i = 0; i < length - 1; i++) { if (c[i] == c[i + 1]) return -1; }	//�ڽĿ� �Ȱ��� �ڽ��� �ִ� == ����Ŭ => Ʈ�� Ż��

	sort(p, p + length);	//����
	for (int i = 0, j = 0; i < length; i++) {	//j�� tmp�ε���
		if (p[i] == p[i + 1] && i < length - 1) continue;		//�θ�� �Է� ���� �͵� ��ġ�°� �ٷ� �ѱ�
		if (!binary_search(c, c + length, p[i])) { tmp[j] = p[i]; j++; }		//p�� �ִ� ���� c�迭 �ȿ� �ִٸ� �� ���� ��Ʈ�� �ƴ�
	}

	if (tmp[1] != 0) return -1;		//tmp 1�� �ε����� 0�� �ƴ� ������ �ִٴ°� ��Ʈ�� �ΰ�
	else if (tmp[0] == 0) return -1;	//tmp 0�� �ε����� 0�̸� ��Ʈ�� ���� �� (����Ŭ ���� ���)
	else return tmp[0];				//tmp 1���� �ƹ��͵� ���� 0���� ������ ������ �� ���� ��Ʈ
}

int main() {
	ifstream inp("tree.inp");
	ofstream out("tree.out");

	int parent[1000000], child[1000000];

	for (int i = 0, j = 1;; i++) {
		inp >> parent[i] >> child[i];		//�Է�

		if (parent[i] == -1 && child[i] == -1) break;		//����
		if (parent[i] == 0 && child[i] == 0) {
			out << "Test Case " << j++ << ": " << isItTree(parent, child, i) << "\n";
			i = -1;
		}
	}

	inp.close();
	out.close();
	return 0;
}