#include <stdio.h>
#pragma warning (disable : 4996)

void bubbleSort(int *a, int len) {
	int tmp, cnt = 0;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				cnt++;
			}
		}

		if (cnt == 0) return;
	}
}

int main() {
	int a[10] = { 2, 3, 5, 6, 7, 1, 0, 4, 9, 8 };
	bubbleSort(a, 10);

	int b[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bubbleSort(b, 10);

	for (int i = 0; i < 10; i++) printf("%d ", a[i]);
	printf("\n");

	for (int i = 0; i < 10; i++) printf("%d ", b[i]);
	printf("\n");

	return 0;
}