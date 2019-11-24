#include <fstream>
#include <cstring>
using namespace std;

ifstream inp("coinmove.inp");
ofstream out("coinmove.out");

int coinarr[100001][7];
int P; //xǥ��
int K; //�ִ��̵��Ÿ�
int S; //�������ΰ�

bool WinOrLose(int index,int move) {
	for (int j = 0; j < K; j++) {
		coinarr[0][j] = false;
	}
	
	if (index < 0) {//�ε����� 0���� ������
		return false;
	}
	if (index % P == 0) {//�ε����� p�� ����̸� //x 
		return false;
	}
	for (int j = 0; j < K; j++) {
		if (j != move) { //�� ����� �̵��Ѱ� ����
			if (coinarr[index][j]==true) {//������ �ϳ��� �̱�� 
				return false; //���� �� 
			}
		}
	}
	return true;

}
int win() {
	for (int i = 0; i < K; i++) {
		if (coinarr[S][i]) {
			return S - i;
		}
	}
	return -1;
}

void Inp() { //2����迭�� �ֱ� L or W
	for (int i = 1; i < S; i++) {
		for (int j = 1; j < K; j++) {
			coinarr[i][j] = WinOrLose(i - j, j);
		}
	}
}

int main() {
	int T;
	inp >> T;
	while (T--) {
		inp >> P >> K >> S;
		Inp();
		out << win() << '/n';
		memset(coinarr, false, sizeof(coinarr));
	}
	return 0;
}
