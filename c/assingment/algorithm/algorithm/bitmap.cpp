#include <fstream>
#include <stdio.h>
#include <string>
#pragma warning (disable: 4996)
using namespace std;

char board[200][200];
string input;
int index, line;

int check(int row_start, int row_dest, int col_start, int col_dest) {
	int size = (row_dest - row_start + 1) * (col_dest - col_start + 1), n = 0, n2 = 0;	//범위, 0갯수, 1갯수

	for (int i = row_start; i <= row_dest; i++) {
		for (int j = col_start; j <= col_dest; j++) {
			if (board[i][j] == '0') {
				n++;
				if (n2) return 2;	//섞인 경우
			}
			else {
				n2++;
				if (n) return 2;	//섞인 경우
			}
		}
	}

	if (n == size) return 0;		//전부 0인 경우
	else return 1;					//전부 1인 경우
}

void B_to_D(FILE* out, int row_start, int row_dest, int col_start, int col_dest) {
	int tmp = check(row_start, row_dest, col_start, col_dest);

	if (tmp == 2) {
		fprintf(out, "D");
		line++;
		if (line == 50) { fprintf(out, "\n"); line = 0; }
		
		int row_divide, col_divide;
		if ((row_dest - row_start + 1) % 2) row_divide = row_start + (row_dest - row_start + 1) / 2;
		else row_divide = row_start + (row_dest - row_start + 1) / 2 - 1;
		if ((col_dest - col_start + 1) % 2) col_divide = col_start + (col_dest - col_start + 1) / 2;
		else col_divide = col_start + (col_dest - col_start + 1) / 2 - 1;

		B_to_D(out, row_start, row_divide, col_start, col_divide);																			//왼쪽 위
		if (col_dest - col_divide != 0) B_to_D(out, row_start, row_divide, col_divide + 1, col_dest);										//오른쪽 위
		if (row_dest - row_divide != 0) B_to_D(out, row_divide + 1, row_dest, col_start, col_divide);										//왼쪽 아래
		if (col_dest - col_divide != 0 && row_dest - row_divide != 0) B_to_D(out, row_divide + 1, row_dest, col_divide + 1, col_dest);		//오른쪽 아래
	}
	else if (tmp == 1) {
		fprintf(out, "1");
		line++;
		if (line == 50) { fprintf(out, "\n"); line = 0; }
	}
	else {
		fprintf(out, "0");
		line++;
		if (line == 50) { fprintf(out, "\n"); line = 0; }
	}
}

void D_to_B(int row_start, int row_dest, int col_start, int col_dest) {
	if (input[index] == '0') {
		for (int i = row_start; i <= row_dest; i++) {
			for (int j = col_start; j <= col_dest; j++) {
				board[i][j] = '0';
			}
		}
	}
	else if (input[index] == '1') {
		for (int i = row_start; i <= row_dest; i++) {
			for (int j = col_start; j <= col_dest; j++) {
				board[i][j] = '1';
			}
		}
	}
	else {
		int row_divide, col_divide;
		if ((row_dest - row_start + 1) % 2) row_divide = row_start + (row_dest - row_start + 1) / 2;
		else row_divide = row_start + (row_dest - row_start + 1) / 2 - 1;
		if ((col_dest - col_start + 1) % 2) col_divide = col_start + (col_dest - col_start + 1) / 2;
		else col_divide = col_start + (col_dest - col_start + 1) / 2 - 1;
		
		index++;
		D_to_B(row_start, row_divide, col_start, col_divide);																			//왼쪽 위
		if (col_dest - col_divide != 0) { index++, D_to_B(row_start, row_divide, col_divide + 1, col_dest); }											//오른쪽 위
		if (row_dest - row_divide != 0) { index++; D_to_B(row_divide + 1, row_dest, col_start, col_divide); }											//왼쪽 아래
		if (col_dest - col_divide != 0 && row_dest - row_divide != 0) { index++; D_to_B(row_divide + 1, row_dest, col_divide + 1, col_dest); }	//오른쪽 아래
	}
}

void print(FILE* out, int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			fprintf(out, "%c", board[i][j]);
			line++;
			if (line == 50) { fprintf(out, "\n"); line = 0; }
		}
	}
}

int main() {
	ifstream inp("bitmap.inp");
	FILE* out = fopen("bitmap.out", "w");

	char type;
	int row, col;
	string tmp;

	while (1) {
		input.clear();
		line = 0;
		index = 0;

		inp >> type;
		if (type == '#') {
			inp.close();
			fclose(out);
			return 0;
		}

		inp >> row >> col;

		if (type == 'B') {
			int size = row * col;
			getline(inp, tmp);

			for (int i = size; i > 0; i -= 50) {
				getline(inp, tmp);
				input.append(tmp);
			}

			int input_index = 0;
			for (int i = 1; i <= row; i++) {
				board[i][0] = ' ';
				for (int j = 1; j <= col; j++) {
					board[i][j] = input[input_index++];
				}
			}

			fprintf(out, "D%4d%4d\n", row, col);
			B_to_D(out, 1, row, 1, col);
			if(line != 0) fprintf(out, "\n");
		}
		else {
			getline(inp, tmp);

			while (1) {
				getline(inp, tmp);
				input.append(tmp);

				if (tmp.length() != 50) break;
			}

			fprintf(out, "B%4d%4d\n", row, col);
			D_to_B(1, row, 1, col);
			print(out, row, col);
			if (line != 0) fprintf(out, "\n");
		}
	}
}