#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("spreadsheet.inp", "rt");
	FILE *out = fopen("spreadsheet.out", "wt");

	int n;
	fscanf(inp, "%d", &n);

	char cell[20] = { 0 };
	int tmp = 0, tmp3 = 0,	//�� ����
		tmp2 = 1,			//������ ����
		cnt = 0, cnt2 = 0;	//�� ���� 

	while (n--) {
		fscanf(inp, "%s", cell);

		if (cell[0] == 'R' && cell[1] < 65) {
			for (int i = 1;; i++) {//R C ���� ���� tmp�� ����
				tmp = (tmp * 10) + (cell[i] - 48);
				cnt++;
				if (cell[i + 1] == 'C') break;
			}

			for (int i = cnt + 2;; i++) {//C ���� ���� tmp3�� ����
				tmp3 = (tmp3 * 10) + (cell[i] - 48);
				if (cell[i + 1] == 0) break;
			}

			for (int i = 0;; i++) {//tmp3�� ���ĺ����� cell�� ����
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
			for (int i = 0; 65 <= cell[i] && cell[i] <= 90; i++) cnt++;//cnt = ���ĺ� �� ����
			for (int i = cnt; 48 <= cell[i] && cell[i] <= 57; i++) cnt2++;//cnt2 = ���� �� ����
			for (int i = 0; i < cnt - 1; i++) tmp2 *= 26;//tmp2 �� 26^cnt ���� 

			for (int i = 0; i < cnt; i++) {//�� ������ �� ���ڵ� ���� tmp�� ����
				tmp += (cell[i] - 64) * tmp2;
				tmp2 /= 26;
			}

			for (int i = cnt; i < cnt + cnt2; i++) //���� ���� tmp3�� ����
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