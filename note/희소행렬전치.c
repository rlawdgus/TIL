#include <stdio.h>
#pragma warning (disable : 4996)

typedef struct {
	int row;
	int col;
	int value;
}sm;

void smTrans(sm a[], sm b[]) {
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (a[0].value > 0) {
		int p = 1;
		for (int i = 0; i < a[0].col; i++) {
			for (int j = 1; j <= a[0].value; j++) {
				if (a[j].col == i) {
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}
		}
	}

	return;
}

int main() {
	sm a[11] = { {8, 7, 10},
				{0, 2, 2},
				{0, 6, 12},
				{1, 4, 7},
				{2, 0, 23},
				{3, 3, 31},
				{4, 1, 14},
				{4, 5, 25},
				{5, 6, 6},
				{6, 0, 52},
				{7, 4, 11} };
	sm b[11];
	smTrans(a, b);

	for (int i = 0; i < 11; i++) 
		printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);

	printf("\n");
	printf("\n");
	for(int i = 0; i < 11; i++)
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);

	return 0;
}