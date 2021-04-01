#include <iostream>
using namespace std;

int main() {
	int num, tmp, result[2];
	cin >> num;

	for (int i = 1;; i++) {
		if (i < num) num -= i;
		else {
			tmp = i;
			break;
		}
	}

	num--;

	if (tmp % 2) {
		result[0] = tmp;
		result[1] = 1;

		while (num--) {
			result[0]--;
			result[1]++;
		}
	}
	else {
		result[0] = 1;
		result[1] = tmp;
		
		while (num--) {
			result[0]++;
			result[1]--;
		}
	}

	cout << result[0] << '/' << result[1];

	return 0;
}