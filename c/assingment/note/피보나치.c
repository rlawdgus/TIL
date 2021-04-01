#include <stdio.h>
#pragma warning (disable : 4996)

int Fibonachi(int num) {
	if (num == 0 || num == 1)
		return 1;

	else
		return Fibonachi(num - 1) + Fibonachi(num - 2);
}

int main() {
	int i;

	scanf("%d", &i);


	for (int j = 0; j < i; j++)
		printf("%d\n", Fibonachi(j));

	return 0;
}