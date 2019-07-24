#include <fstream>
#include <vector>
#include <stack>
using namespace std;

//��ǲ�� ����� �ȴ� ���� ������ ÷�ڰ� ���ڸ� �̻��� �͵��� ����� ���޴´�

vector< string > str;
stack< char > st;
char num = 48;

void input(char ch, int index, ifstream *inp, ofstream *out) {
	while (index >= str.size()) str.push_back(" ");	//���� �ڸ����� ä���
	
	if (ch > 64 && ch < 91) {
		string tmp;
		tmp += ch;	//���� 
		*out << ch;

		while (ch > 47 && ch < 58) {	//÷��
			tmp += ch;
			*out << ch;
			*inp >> ch;
		}
		*out << ' ';

		str[index] = tmp;
		return;
	}
	else if (ch == '(') {
		*out << "( ";
		st.push('(');

		string tmp = "r";
		tmp += num++;
		str[index] = tmp;

		*inp >> ch;
		input(ch, index * 2, inp, out);
		input(ch, index * 2 + 1, inp, out);
	}
	else {
		*out << ") ";
		st.pop();
	}
}

void pre_order(int index, ofstream *out) {
	if (str[index][0] > 64 && str[index][0] < 91) {
		for (int i = 0; i < 2; i++) *out << str[index][i];
		*out << '\n';
	}
	else {
		for (int i = 0; i < 2; i++) *out << str[index][i];
		*out << '\n';
		pre_order(index * 2, out);
		pre_order(index * 2 + 1, out);
	}
}

void in_order(int index, ofstream *out) {
	if (str[index][0] > 64 && str[index][0] < 91) {
		for (int i = 0; i < 2; i++) *out << str[index][i];
		*out << '\n';
	}
	else {
		in_order(index * 2, out);
		for (int i = 0; i < 2; i++) *out << str[index][i];
		*out << '\n';
		in_order(index * 2 + 1, out);
	}
}

int main() {
	ifstream inp("tree.inp");
	ofstream out("tree.out");

	int T;
	char ch;

	inp >> T;
	while (T--) {
		inp >> ch;
		input(ch, 1, &inp, &out);
		while (st.size() != 0) {
			inp >> ch;	//���� ��ȣ �ޱ�
			st.pop();
			out << ") ";
		}

		out << "\nPreorder\n";
		pre_order(1, &out);

		out << "Inorder\n";
		in_order(1, &out);

		str.clear();
		num = 48;
	}

	inp.close();
	out.close();
	return 0;
}