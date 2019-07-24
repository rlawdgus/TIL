#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("spreadsheet.inp", "rt");
	FILE *out = fopen("spreadsheet.out", "wt");

	int n;
	fscanf(inp, "%d", &n);

	char cell[20] = { 0 };
	int tmp = 0, tmp3 = 0,	//수 저장
		tmp2 = 1,			//제곱수 저장
		cnt = 0, cnt2 = 0;	//수 길이 

	while (n--) {
		fscanf(inp, "%s", cell);

		if (cell[0] == 'R' && cell[1] < 65) {
			for (int i = 1;; i++) {//R C 사이 수를 tmp에 저장
				tmp = (tmp * 10) + (cell[i] - 48);
				cnt++;
				if (cell[i + 1] == 'C') break;
			}

			for (int i = cnt + 2;; i++) {//C 이후 수를 tmp3에 저장
				tmp3 = (tmp3 * 10) + (cell[i] - 48);
				if (cell[i + 1] == 0) break;
			}

			for (int i = 0;; i++) {//tmp3을 알파벳으로 cell에 저장
				if (tmp3 % 26 == 0) {
					cell[i] = 90;
					tmp3 = tmp3 / 26 - 1;
					cnt2++;
					if (tmp3 == 0) break;
				}
				else if (tmp3 < 26) { cell[i] = tmp3 + 64; cnt2++; break; }
				else {
					cell[i] = tmp3 % 26 + 64;
					tmp3 /= 26;
					cnt2++;
				}
			}

			for (int i = cnt2 - 1; i >= 0; i--) fprintf(out, "%c", cell[i]);
			fprintf(out, "%d\n", tmp);
		}
		else {
			for (int i = 0; 65 <= cell[i] && cell[i] <= 90; i++) cnt++;//cnt = 알파벳 수 저장
			for (int i = cnt; 48 <= cell[i] && cell[i] <= 57; i++) cnt2++;//cnt2 = 숫자 수 저장
			for (int i = 0; i < cnt - 1; i++) tmp2 *= 26;//tmp2 에 26^cnt 저장 

			for (int i = 0; i < cnt; i++) {//수 나오기 전 문자들 수로 tmp에 저장
				tmp += (cell[i] - 64) * tmp2;
				tmp2 /= 26;
			}

			for (int i = cnt; i < cnt + cnt2; i++) //남은 수들 tmp3에 저장
				tmp3 = (tmp3 * 10) + cell[i] - 48;

			for (int i = 0; i < 4; i++) {
				if (i == 0) fprintf(out, "R");
				else if (i == 1) fprintf(out, "%d", tmp3);
				else if (i == 2) fprintf(out, "C");
				else fprintf(out, "%d", tmp);
			}
			fprintf(out, "\n");
		}

		tmp = 0, tmp2 = 1, tmp3 = 0, cnt = 0, cnt2 = 0;
	}

	fclose(inp);
	fclose(out);
	return 0;
}