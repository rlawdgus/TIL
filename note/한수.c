#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int num, temp, count = 0;
	int N1, N2, N3;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (0 < i && i < 100)
			count++;

		else if (i == 1000)
			continue;

		else {
			N1 = (i / 100) % 10;
			N2 = (i / 10) % 10;
			N3 = i % 10;

			if ((N1 - N2) == (N2 - N3))
				count++;
		}
	}

	printf("%d\n", count);

	return 0;
}