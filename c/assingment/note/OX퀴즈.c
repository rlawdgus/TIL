#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main() {
	int testcase, count = 0, score = 0;
	char arr[80] = { "O" };

	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		scanf("%s", arr);

		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == 'O') {
				count++;
				score += count;
			}

			else if (arr[j] == "\0")
				continue;

			else
				count = 0;
		}

		printf("%d\n", score);
		score = 0;
		count = 0;
	}

	return 0;
}