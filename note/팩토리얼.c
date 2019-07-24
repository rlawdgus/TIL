#include <stdio.h>
#pragma warning (disable : 4996)

int Factorial(int num) {
	if (num < 2)
		return 1;

	else
		return num * Factorial(num - 1);
}

int main() {
	int i;

	scanf("%d", &i);

	printf("%d\n", Factorial(i));

	return 0;
}