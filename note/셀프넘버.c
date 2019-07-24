#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int num;
	int arr[10001] = { 0 };

	for (int i = 1; i <= 10000; i++) {
		num = i;

		for (int j = 1000; j >= 1; j /= 10)
			num += (i / j) % 10;

		if (num <= 10000)
			arr[num] = 1;

	}

	for (int k = 1; k <= 10000; k++) {
		if (arr[k] == 0)
			printf("%d\n", k);
	}

	return 0;
}