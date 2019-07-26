#include <fstream>
using namespace std;

bool friends[10][10];
bool check[10];

int picnic(int n) {
	bool finished = true;
	int tmp;

	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			tmp = i;
			finished = false;
			break;
		}
	}
	if (finished) return 1;

	int result = 0;

	for (int i = tmp + 1; i < n; i++) {
		if (!check[tmp] && !check[i] && friends[tmp][i]) {
			check[tmp] = check[i] = true;
			result += picnic(n);
			check[tmp] = check[i] = false;
		}
	}

	return result;
}

int main() {
	ifstream inp("picnic.inp");
	ofstream out("picnic.out");

	int C, n, m, a, b;

	inp >> C;
	while (C--) {
		inp >> n >> m;
		while (m--) {
			inp >> a >> b;
			friends[a][b] = true;
			friends[b][a] = true;
		}

		out << picnic(n) << '\n';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) friends[i][j] = false;
		}
	}

	inp.close();
	out.close();
	return 0;
}