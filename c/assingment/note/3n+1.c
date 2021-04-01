#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int max = 0, length = 0;
	long long int i, j, tmp;
	while (scanf("%lld %lld", &i, &j) == 2) {
		printf("%lld %lld ", i, j);
		if (i > j) {
			tmp = i;
			i = j;
			j = tmp;
		}
		for (i; i <= j; i++) {
			tmp = i;
			for (;;) {
				if (tmp == 1) {
					length++;
					break;
				}
				if (tmp % 2 == 0) {
					tmp /= 2;
					length++;
				}
				else {
					tmp = 3 * tmp + 1;
					length++;
				}
			}
			max = max > length ? max : length;
			length = 0;
		}
		printf("%lld\n", max);
		max = 0;
	}

	return 0;
}