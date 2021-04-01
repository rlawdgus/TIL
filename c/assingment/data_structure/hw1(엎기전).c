#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float BigO_N(int num) {
	return num;
}

float BigO_LogN(int num) {
	return log(num)/log(2);
}

float BigO_NLogN(int num) {
	return num * BigO_LogN(num);
}

float BigO_2eN(int num) {
	return pow(2, num);
}

float BigO_Fact(int num){
	if (num <= 1)
		return 1;
	return num * BigO_Fact(num - 1);
}

int main() {
	FILE *input_fp = fopen("hw1.inp", "rt");
	FILE *output_fp = fopen("hw1.out", "wt");

	if ((input_fp = fopen("hw1.inp", "rt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw1.inp");

	if ((output_fp = fopen("hw1.out", "wt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw1.out");

	char num;

	float *big_o = (float *)malloc(sizeof(float) * 5);

	for (;;) {
		fscanf(input_fp, "%c", &num);

		if (num == '*') {
			fprintf(output_fp, "*");
			break;
		}

		else if (num == 10)
			continue;

		else {
			big_o[0] = BigO_N(num - 48);
			fprintf(output_fp, "1)%d ", (int)big_o[0]);

			big_o[1] = BigO_LogN(num - 48);
			fprintf(output_fp, "2)%d ", (int)big_o[1]);

			big_o[2] = BigO_NLogN(num - 48);
			fprintf(output_fp, "3)%d ", (int)big_o[2]);

			big_o[3] = BigO_2eN(num - 48);
			fprintf(output_fp, "4)%d ", (int)big_o[3]);

			big_o[4] = BigO_Fact(num - 48);
			fprintf(output_fp, "5)%d", (int)big_o[4]);
		}

		fprintf(output_fp, "\n");
	}

	fclose(input_fp);
	fclose(output_fp);
	free(big_o);

	return 0;
}