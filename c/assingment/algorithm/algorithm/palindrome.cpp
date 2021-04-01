#include <fstream>
#include <string>
using namespace std;

int board[1001][1001];

int palindrome(string input, string reverse) {
	int size = input.size();

	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (input[j] == reverse[i]) board[i][j] = board[i - 1][j - 1] + 1;
			else board[i][j] = board[i - 1][j] > board[i][j - 1] ? board[i - 1][j] : board[i][j - 1];
		}
	}

	return size - board[size - 1][size - 1] - 1;
}

int main() {
	ifstream inp("palindrome.inp");
	ofstream out("palindrome.out");

	int T;
	string input;

	inp >> T;
	while (T--) {
		inp >> input;
		string reverse(input.rbegin(), input.rend());

		string tmp, tmp2;
		tmp = "0" + input;
		tmp2 = "0" + reverse;

		int result = palindrome(tmp, tmp2);

		if (result >= 3) out << "-1\n";
		else out << result << '\n';
	}

	return 0;
}