#include <fstream>
#include <algorithm>
#define MAX 1000
using namespace std;

int early[MAX][MAX];
int late[MAX][MAX];

int main() {
	ifstream inp("card2.inp");
	ofstream out("card2.out");

	int T, n, num;

	inp >> T;
	while (T--) {
		inp >> n;
		for (int i = 0; i < n; i++) inp >> early[i][i];
		for (int i = 0, j = 1; j < n; i++, j++) {
			early[i][j] = max(early[i][j - 1], early[i + 1][j]);
			late[i][j] = min(early[i][j - 1], early[i + 1][j]);
		}
		/*
		for (int i = 0, k = 2, j = 2;; i++, j++) {
			early[i][j] = max(early[i][i] + late[i + 1][j], early[j][j] + late[i][j - 1]);
			late[i][j] = min(early[i + 1][j], early[i][j - 1]);

			if (i == 0 && j == n - 1) { out << early[i][j] << '\n'; break; }
			else if (j == n - 1) { i = -1, j = -1 + ++k; }
		}
		*/
		//////////////////////////////////////////////////
		for (int j = 1; j < n; j++) {
			for (int i = 0; i + j < n; i++) {
				early[i][i + j] = max(early[i][i] + late[i + 1][i + j], early[i + j][i + j] + late[i][i + j - 1]);
				late[i][i + j] = min(early[i][i + j - 1], early[i + 1][i + j]);
			}
		}
		out << early[0][n - 1] << '\n';
		/////////////////////////////////////////////////
	}

	inp.close();
	out.close();
	return 0;
}