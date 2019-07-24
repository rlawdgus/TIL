#include <fstream>
#include <string>
using namespace std;

//추가해야하는 경우 예) QnQCWIdddQdIWCQn
//양쪽 모두 한 칸 앞이 다를 때도 잘 안되는거 같다

int nearby(string str, int index, int index2) {	//다음문자와 같은거 나올 때까지의 거리
	int dis = 0, dis2 = 0;

	for (int i = index; i <= index2; i++) {
		if (str[i] == str[index2]) break;
		dis++;
	}

	for (int i = index2; i >= index; i--) {
		if (str[i] == str[index]) break;
		dis2++;
	}

	if (dis < dis2) return 1;	//i가 가까우니까 i++
	else return 0;	//j가 가까우니까 j--
}

int palindrome(string str) {
	int cnt = 0;

	for (int i = 0, j = str.length() - 1;;) {
		if (cnt > 2) return -1;
		if (i >= j) return cnt;

		if (str[i] == str[j]) { i++; j--; }
		else {
			if (str[i] == str[j - 1]) { cnt++; j--; }
			else if (str[i + 1] == str[j]) { cnt++; i++; }
			else {	//둘 다 다를 때
				cnt++;
				if (nearby(str, i, j)) i++;
				else j--;
			}
		}
	}
}

int main() {
	ifstream inp("palindrome.inp");
	ofstream out("palindrome.out");

	int T;
	string str;

	inp >> T;
	while (T--) {
		inp >> str;
		out << palindrome(str) << '\n';
	}

	inp.close();
	out.close();
	return 0;
}