#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int length, length2;
int dp[5002][5002], tmp[5002][26], tmp2[5002][26];
string input, input2;

int get_len(int x, int y, int c) {
	int ret = 0, ret2 = 0;

	if (tmp[x][c] + tmp2[y][c] == tmp[length - 1][c] + tmp2[length2 - 1][c]) ret = x + y;
	if (tmp[x][c] + tmp2[y][c] == 1) ret2 = x + y;

	return ret - ret2;
}

void solve() {
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < 26; j++) tmp[i][j] = tmp[i - 1][j];

		tmp[i][input[i] - 'A']++;
	}

	for (int i = 1; i < length2; i++) {
		for (int j = 0; j < 26; j++) tmp2[i][j] = tmp2[i - 1][j];

		tmp2[i][input2[i] - 'A']++;
	}

	dp[0][0] = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length2; j++) {
			int ret = get_len(i + 1, j, input[i + 1] - 'A');
			int ret2 = get_len(i, j + 1, input2[j + 1] - 'A');
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + ret);
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + ret2);
		}
	}
}

int main() {
	ifstream inp("color.inp");
	ofstream out("color.out");

	int T;
	string input_tmp;

	inp >> T;
	while (T--) {
		input = input2 = '*';
		inp >> input_tmp;
		input = input + input_tmp;
		length = input.size();
		
		inp >> input_tmp;
		input2 = input2 + input_tmp;
		length2 = input2.size();

		for (int i = 0; i <= length; i++) {
			for (int j = 0; j <= length2; j++) dp[i][j] = 9999999;
		}

		for (int i = 0; i <= length; i++) {
			for (int j = 0; j < 26; j++) tmp[i][j] = 0;
		}
		
		for (int i = 0; i <= length2; i++) {
			for (int j = 0; j < 26; j++) tmp2[i][j] = 0;
		}

		solve();

		out << dp[length - 1][length2 - 1] << '\n';
	}

	return 0;
}