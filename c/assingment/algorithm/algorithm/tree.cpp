#include <fstream>
#include <string>
#include <stack>
using namespace std;

void pre_order(string input, ofstream& out) {
	out << "Preorder\n";
	int root_num = 0, length = input.size();

	for (int i = 0; i < length;) {
		if (input[i] == '(') out << 'r' << root_num++ << '\n';
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			for (; input[i] != ' '; i++) out << input[i];
			out << '\n';
		}
		i++;
	}
}

void in_order(string input, ofstream& out) {
	out << "Inorder\n";
	int root_num = 0, length = input.size();
	stack< int > st;
	
	for (int i = 0; i < length;) {
		if (input[i] == '(') st.push(root_num++);
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			for (; input[i] != ' '; i++) out << input[i];
			out << '\n';
			if (!st.empty()) { out << 'r' << st.top() << '\n'; st.pop(); }
		}
		i++;
	}
}

int main() {
	ifstream inp("tree.inp");
	ofstream out("tree.out");

	int T;
	string input;

	inp >> T;
	getline(inp, input);
	while (T--) {
		getline(inp, input);
		out << input << '\n';

		pre_order(input, out);
		in_order(input, out);
	}

	return 0;
}