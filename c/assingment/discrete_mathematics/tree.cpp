#include <fstream>
#include <algorithm>
using namespace std;

int isItTree(int p[], int c[], int length) {//p는 부모노드들 c는 자식노드들 배열
	int tmp[2] = { 0 };	//tmp에 루트를 저장함 (루트가 두 개 이상 들어오면 걍 트리 탈락
	sort(c, c + length);	//정렬
	for (int i = 0; i < length - 1; i++) { if (c[i] == c[i + 1]) return -1; }	//자식에 똑같은 자식이 있다 == 사이클 => 트리 탈락

	sort(p, p + length);	//정렬
	for (int i = 0, j = 0; i < length; i++) {	//j는 tmp인덱스
		if (p[i] == p[i + 1] && i < length - 1) continue;		//부모로 입력 받은 것들 겹치는거 바로 넘김
		if (!binary_search(c, c + length, p[i])) { tmp[j] = p[i]; j++; }		//p에 있는 것이 c배열 안에 있다면 그 놈은 루트가 아님
	}

	if (tmp[1] != 0) return -1;		//tmp 1번 인덱스에 0이 아닌 뭔가가 있다는건 루트가 두개
	else if (tmp[0] == 0) return -1;	//tmp 0번 인덱스가 0이면 루트가 없는 것 (사이클 같은 경우)
	else return tmp[0];				//tmp 1번에 아무것도 없고 0번에 뭔가가 있으면 그 놈이 루트
}

int main() {
	ifstream inp("tree.inp");
	ofstream out("tree.out");

	int parent[1000000], child[1000000];

	for (int i = 0, j = 1;; i++) {
		inp >> parent[i] >> child[i];		//입력

		if (parent[i] == -1 && child[i] == -1) break;		//종료
		if (parent[i] == 0 && child[i] == 0) {
			out << "Test Case " << j++ << ": " << isItTree(parent, child, i) << "\n";
			i = -1;
		}
	}

	inp.close();
	out.close();
	return 0;
}