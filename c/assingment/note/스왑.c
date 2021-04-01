#include <stdio.h>
#pragma warning (disable : 4996)

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

int main() {
	int a = 0, b = 1;

	swap(&a, &b);

	printf("%d %d\n", a, b);

	return 0;
}