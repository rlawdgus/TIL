#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int *board;
int *newBoard;

int strike(int num, int num2) {
	int elmt[4], elmt2[4], cnt = 0, j = 0;
	for (int i = 1000, j = 0; i >= 1; i /= 10, j++) elmt[j] = (num / i) % 10;
	for (int i = 1000, j = 0; i >= 1; i /= 10, j++) elmt2[j] = num2 / i % 10;
	for (int i = 0; i < 4; i++) if (elmt[i] == elmt2[i]) cnt++;

	return cnt;
}

int ball(int num, int num2) {
	int elmt[4], elmt2[4], cnt = 0;
	for (int i = 1000, j = 0; i >= 1; i /= 10, j++) elmt[j] = (num / i) % 10;
	for (int i = 1000, j = 0; i >= 1; i /= 10, j++) elmt2[j] = num2 / i % 10;

	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (i != j && elmt[j] == elmt2[i]) cnt++;

	return cnt;
}

int check(int num, int s, int b, int size) {
	int cnt = 0;
	newBoard = (int *)malloc(sizeof(int) * 3024);
	for (int i = 0; i < size; i++) {
		if (strike(board[i], num) == s && ball(board[i], num) == b) {
			newBoard[cnt] = board[i];
			cnt++;
		}
	}

	board = newBoard;
	return cnt;
}

int main() {
	FILE *inp = fopen("numgame.inp", "rt");
	FILE *out = fopen("numgame.out", "wt");

	int T, k, num, s, b, size = 3024;
	board = (int *)malloc(sizeof(int) * 3024);

	fscanf(inp, "%d", &T);
	while (T--) {
		num = 1234;
		size = 3024;
		for (int i = 0; num < 9877; num++) {
			int a = num / 1000 % 10;
			int b = num / 100 % 10;
			int c = num / 10 % 10;
			int d = num % 10;

			if (a != 0 && b != 0 && c != 0 && d != 0) {
				if (a != b && a != c && a != d && b != c && b != d && c != d) {
					board[i] = num;
					i++;
				}
			}
		}

		fscanf(inp, "%d", &k);
		while (k--) {
			fscanf(inp, "%d %d %d", &num, &s, &b);
			size = check(num, s, b, size);
		}

		fprintf(out, "%d\n", size);
		if (size < 7) for (int i = 0; i < size; i++) fprintf(out, "%d\n", board[i]);
		else {
			for (int i = 0; i < 3; i++) fprintf(out, "%d\n", board[i]);
			for (int i = size - 3; i < size; i++) fprintf(out, "%d\n", board[i]);
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}