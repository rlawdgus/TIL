#include <stdio.h>
#pragma warning (disable : 4996)

int main() {	//Ʋ�ȴ�
	int a, b, v;

	scanf("%d %d %d", &a, &b, &v);

	int day = ((v - a) / (a - b)) + 1;

	printf("%d\n", day);

	return 0;
}