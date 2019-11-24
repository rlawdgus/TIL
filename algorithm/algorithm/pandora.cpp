#include <fstream>
#include <string>
using namespace std;

int pandora(string input) {
	int x = 1, y = 1, size = input.size(), dir = 0;

	for (int i = 0, j; i < size; i++) {
		j = (i + 1) % size;

		if (input[i] == 'R' && input[j] == 'R') {
			if (dir & 1) x = 0;	//비트연산자
			else y = 0;
		}

		if (input[i] == 'L') dir = (dir + 3) % 4;
		else dir = (dir + 1) % 4;
	}

	return x + y;
}

int main() {
	ifstream inp("pandora.inp");
	ofstream out("pandora.out");

	int T;
	string input;

	inp >> T;
	getline(inp, input);

	while (T--) {
		getline(inp, input);
		out << pandora(input) << '\n';
	}

	inp.close();
	out.close();
	return 0;
}