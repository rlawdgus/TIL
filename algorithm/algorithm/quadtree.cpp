#include <fstream>
#include <string>
using namespace std;

string result;
int index = 0;

void quadtree(string str, int index) {
	if (str[index] == 'x') {
		result += str[index];
		
		quadtree(str, index + 3);
		quadtree(str, index + 4);
		quadtree(str, index + 1);
		quadtree(str, index + 2);
	}
	else result += str[index];
}

int main() {
	ifstream inp("quadtree.inp");
	ofstream out("quadtree.out");

	int C;
	string str;

	inp >> C;
	while (C--) {
		inp >> str;
		quadtree(str, 0);
		for (int i = 0; i < str.length(); i++) out << str[i];
		out << '\n';
	}

	inp.close();
	out.close();
	return 0;
}



//hanoi(int n, char A, char B, char C) { A�� �ִ°�, B�� ������ �Ѱ�, C�� ������
//	if (n == 1) {
//		cout << A << ' ' << C << endl;	// == �������� �����ٴ� ��
//		return;
//	}
//
//	hanoi(n - 1, A, C, B);
//	cout << A << ' ' << C << endl;
//	hanoi(n - 1, B, A, C);
//	return;
//}