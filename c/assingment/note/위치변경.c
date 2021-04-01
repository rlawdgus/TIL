#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void Exchange(int *arr, int num1, int num2) {
	int temp1 = -1, index1;
	int temp2 = -1, index2;

	for (int i = 0; i < _msize(arr) / sizeof(int); i++) {
		if (arr[i] == num1) {
			index1 = i;
			temp1 = num1;
		}
		if (arr[i] == num2) {
			index2 = i;
			temp2 = num2;
		}
	}

	if (temp1 != -1 && temp2 != -1) {
		arr[index1] = temp2;
		arr[index2] = temp1;

		for (int j = 0; j < _msize(arr) / sizeof(int); j++)
			printf("%d ", arr[j]);

		printf("\n");
	}
	else if (temp1 == -1)
		printf("%d(이)가 배열에 없다.\n", num1);

	else if (temp2 == -1)
		printf("%d(이)가 배열에 없다.\n", num2);
}

int main() {
	int L, num1, num2;

	scanf("%d", &L);
	int *arr = (int *)malloc(sizeof(int) * L);

	for (int i = 0; i < L; i++)
		scanf("%d", arr + i);

	scanf("%d %d", &num1, &num2);	//바꿀 수
	Exchange(arr, num1, num2);

	free(arr);
	return 0;
}