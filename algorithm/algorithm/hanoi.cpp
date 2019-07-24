#include <fstream>
using namespace std;

void hanoi(int n, char A, char B, char C, ofstream *out) { //A�� �ִ°�, B�� ������ �Ѱ�, C�� ������
	if (n == 1) {
		*out << A << ' ' << C << endl;	// == �������� �����ٴ� ��
		return;
	}

	hanoi(n - 1, A, C, B, out);
	*out << A << ' ' << C << endl;
	hanoi(n - 1, B, A, C, out);
	return;
}

int main() {
	ifstream inp("hanoi.inp");
	ofstream out("hanoi.out");

	int num;
	while (1) {
		inp >> num;
		if (num == -1) {
			inp.close();
			out.close();
			return 0;
		}

		hanoi(num, 'A', 'B', 'C', &out);
		out << '\n';
	}
}