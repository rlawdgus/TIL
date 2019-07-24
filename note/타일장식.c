#include <stdio.h>
#pragma warning (disable : 4996)

long long fibonachi(long long num) {
	long long a = 1L, b = 1L, temp = 0L;

	if (num <= 2) return 1;

	for (int i = 2; i < num; i++) {
		temp = a + b;
		a = b;
		b = temp;
	}

	return temp;
}

int main() {
	long long num, L;

	scanf("%lld", &num);

	if (num == 1) printf("%d\n", 4);
	else if (num == 2) printf("%d\n", 6);
	else {
		L = (fibonachi(num) + fibonachi(num + 1)) * 2;
		printf("%lld\n", L);
	}

	return 0;
}