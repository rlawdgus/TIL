#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int compare(const void *a, const void *b) {		//오름차순
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	return num1 - num2;
}
int compare2(const void *a, const void *b) {	//내림차순
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	return num2 - num1;
}
int main() {
	int a[10] = { 2, 3, 5, 6, 7, 4, 1, 8, 9, 0 };
	qsort(a, 10, sizeof(int), compare);

	for (int i = 0; i < 10; i++) printf("%d ", a[i]);
	printf("\n");

	qsort(a, 10, sizeof(int), compare2);

	for (int i = 0; i < 10; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}