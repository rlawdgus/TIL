#include <fstream>
#include <string>
using namespace std;

//�߰��ؾ��ϴ� ��� ��) QnQCWIdddQdIWCQn
//���� ��� �� ĭ ���� �ٸ� ���� �� �ȵǴ°� ����

int nearby(string str, int index, int index2) {	//�������ڿ� ������ ���� �������� �Ÿ�
	int dis = 0, dis2 = 0;

	for (int i = index; i <= index2; i++) {
		if (str[i] == str[index2]) break;
		dis++;
	}

	for (int i = index2; i >= index; i--) {
		if (str[i] == str[index]) break;
		dis2++;
	}

	if (dis < dis2) return 1;	//i�� �����ϱ� i++
	else return 0;	//j�� �����ϱ� j--
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
			else {	//�� �� �ٸ� ��
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