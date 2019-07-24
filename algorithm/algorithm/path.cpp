#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

long long dp[16] = { 0 };

int factorial(int num) {
	if (num <= 2) return num;
	else if (dp[num]) return dp[num];
	else {
		dp[num] = num * factorial(num - 1);
		return dp[num];
	}
}

int path(int M, int N) {	//길 갯수 반환
	if (!M || !N) return 1;

	int x, y;
	long long result = 1;

	if (M > N) { x = M; y = N; }
	else	   { x = N; y = M; }

	for (int i = x + y, j = y; j > 0; i--, j--) result *= i;
	result /= factorial(y);

	return (int)result;
}

int waypoint(int M, int N, int K) {	//경유지 찾기
	int x, y;

	y = K / M;

	x = K % M - 1;
	if (x == -1) { x = M - 1; y--; }

	return path(x, y) * path(M - x - 1, N - y - 1);
}

int main() {
	double start = time(NULL);

	ifstream inp("path.inp");
	ofstream out("path.out");

	int T, N, M, K;

	inp >> T;
	while (T--) {
		inp >> N >> M >> K;

		if (K) out << waypoint(M, N, K) << '\n';
		else out << path(M - 1, N - 1) << '\n';
	}

	inp.close();
	out.close();

	double end = time(NULL);
	cout << end - start;
	return 0;
}