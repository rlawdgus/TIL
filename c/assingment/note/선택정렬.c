#include <stdio.h>
#pragma warning (disable : 4996)

void selectionSort(int *a, int len) {
	int min, tmp;

	for (int i = 0; i < len - 1; i++) {
		min = i;

		for (int j = i; j < len; j++) min = a[min] < a[j] ? min : j;

		tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
	}
}

int main() {
	int a[10] = { 2, 3, 5, 6, 7, 4, 1, 8, 9, 0 };
	selectionSort(a, 10);

	for (int i = 0; i < 10; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}