#include <fstream>
#include <string>
using namespace std;

char board[5][5];

bool boggle(string str, int index, int x, int y) {
	if (x < 0 || y < 0 || x > 4 || y > 4) return false;
	if (str[index] == board[x][y] && index == str.length() - 1) return true;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (boggle(str, index + 1, x + i, y + j)) return true;
		}
	}

	return false;
}

int main() {
	ifstream inp("boggle.inp");
	ofstream out("boggle.out");

	int T, N;
	inp >> T;

	char ch;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			inp >> ch;
			board[i][j] = ch;
		}
	}

	string str;
	bool tmp = false;

	inp >> N;
	N++;
	while (N--) {
		getline(inp, str);
		if (str.length() != 0) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (str[0] == board[i][j]) tmp = boggle(str, 1, i, j);
					if (tmp == true) break;
				}

				if (tmp == true) break;
			}

			if (tmp == true) out << str << " YES\n";
			else out << str << " NO\n";
		}
	}

	inp.close();
	out.close();
	return 0;
}