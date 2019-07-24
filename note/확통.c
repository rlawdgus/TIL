#include <stdio.h>
#pragma warning (disable : 4996)

int P(int n, int k) {
	if (k == 0) return 1;
	else return n * P(n - 1, k - 1);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d\n", P(n, k));
}