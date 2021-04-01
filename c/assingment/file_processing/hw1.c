#include <stdio.h>
#pragma warning (disable : 4996)

int compare(int a[], int b[], int size) {	//다르면 1, 같으면 0
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i]) return 1;
	}
	return 0;
}

void intervalSort(int a[], int begin, int end, int interval) {
	int i, j, item;
	for (i = begin + interval; i <= end; i = i + interval) {
		item = a[i];
		for (j = i - interval; j >= begin && item < a[j]; j = j - interval)
			a[j + interval] = a[j];
		a[j + interval] = item;
	}
}

void shellSort(int a[], int size, int tmp[], FILE *out) {
	int i, t, interval;
	interval = size / 2;
	while (interval >= 1) {
		for (i = 0; i < interval; i++)
			intervalSort(a, i, size - 1, interval);
		/*if (compare(a, tmp, size)) {
			for (t = 0; t < size; t++) {
				fprintf(out, "%d ", a[t]);
				tmp = a;
			}
			
			fprintf(out, "\n");
		}//변화 있어야 출력*/
		for (t = 0; t < size; t++) fprintf(out, "%d ", a[t]);
		fprintf(out, "\n");		//변화 없어도 출력*/
		interval = interval / 2;
	}
}

void twoWayMerge(int a[], int length, int b[], int length2, FILE *out) {
	for(int i = 0, j = 0;;) {
		//for (; i < length && a[i] == a[i + 1];) i++;
		//for (; j < length2 && b[j] == b[j + 1];) j++;

		if (i == length && j == length2) break;
		else if (i == length) { fprintf(out, "%d ", b[j]); j++; }
		else if (j == length2) { fprintf(out, "%d ", a[i]); i++; }
		else if (a[i] == b[j]) {
			fprintf(out, "%d %d ", a[i], b[j]);
			i++;
			j++;
		}
		else if (a[i] < b[j]) {
			fprintf(out, "%d ", a[i]);
			i++;
		}
		else if (a[i] > b[j]) {
			fprintf(out, "%d ", b[j]);
			j++;
		}
	}

	fprintf(out, "\n");
}

int check(int a[], int size, int num) {	//중복 확인 중복 1, 중복x 0
	for (int i = 0; i < size; i++) {
		if (a[i] == num) return 1;
	}
	return 0;
}

int main() {
	FILE *inp = fopen("hw1.inp", "rt");
	FILE *out = fopen("hw1.out", "wt");

	if ((inp = fopen("hw1.inp", "rt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw1.inp");

	if ((out = fopen("hw1.out", "wt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw1.out");

	int arr[100000], arr2[100000], tmp[100000];
	int num, cnt = 0, length = 0, length2 = 0;
	char ch;

	while (1) {
		for (int i = 0;; i++) {
			fscanf(inp, "%d", &num);
			ch = fgetc(inp);
			if (ch == '*') break;

			if (cnt == 0) { arr[i] = num; length++; }
			else if (cnt == 1) { arr2[i] = num; length2++; }

			if (ch == '\n') { cnt++; i = -1; }

			if (cnt == 2) {
				shellSort(arr, length, tmp, out);
				shellSort(arr2, length2, tmp, out);

				twoWayMerge(arr, length, arr2, length2, out);
				cnt = 0;
				length = 0;
				length2 = 0;
			}
		}
		if (ch == '*') break;
	}
	fprintf(out, "*");

	fclose(inp);
	fclose(out);
	return 0;
}