#include <fstream>
#include <cstring>
using namespace std;

ifstream inp("coinmove.inp");
ofstream out("coinmove.out");

int coinarr[100001][7];
int P; //x표시
int K; //최대이동거리
int S; //동전놓인곳

bool WinOrLose(int index,int move) {
	for (int j = 0; j < K; j++) {
		coinarr[0][j] = false;
	}
	
	if (index < 0) {//인덱스가 0보다 작으면
		return false;
	}
	if (index % P == 0) {//인덱스가 p의 배수이면 //x 
		return false;
	}
	for (int j = 0; j < K; j++) {
		if (j != move) { //전 사람이 이동한거 말고
			if (coinarr[index][j]==true) {//상대방이 하나라도 이기면 
				return false; //내가 져 
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

void Inp() { //2차언배열에 넣기 L or W
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
