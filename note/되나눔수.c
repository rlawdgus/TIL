#include <stdio.h>
#pragma warning (disable : 4996)

void reDivide(int num1, int num2) {
	int count = 0;
	int rDiv = 0;

	for (int i = num1; i <= num2; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				count++;	//약수 갯수
		}

		if (i % count == 0)		//되나눔 되는 경우
			rDiv++;
		
		count = 0;
	}
	printf("%d\n", rDiv);
}

int main() {
	int testcase;
	int num1, num2;

	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		scanf("%d %d", &num1, &num2);
		reDivide(num1, num2);
	}

	return 0;
}