#include <iostream>
#include <algorithm>
using namespace std;

int cost[1000][3];
int paint[1000][3];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < 3; i++) paint[0][i] = cost[0][i];

	for (int i = 1; i <= N; i++) {
		paint[i][0] = min(paint[i - 1][1], paint[i - 1][2]) + cost[i][0];
		paint[i][1] = min(paint[i - 1][0], paint[i - 1][2]) + cost[i][1];
		paint[i][2] = min(paint[i - 1][0], paint[i - 1][1]) + cost[i][2];
	}

	cout << min(min(paint[N][0], paint[N][1]), paint[N][2]);

	return 0;
}