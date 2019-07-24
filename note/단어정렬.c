#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)	//->, [] 참조 포함

typedef struct data {
	char str[51];
	int len;
}Data;
int compare(Data *a, Data *b) {
	if (a->len != b->len) return a->len - b->len;
	else {
		for (int i = 0; i < a->len; i++) {
			if (a->str[i] < b->str[i]) return -1;
			else if(a->str[i] > b->str[i]) return 1;
		}
		return 0;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	Data *data = (Data *)malloc(sizeof(Data) * N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &data[i].str);
		data[i].len = strlen(data[i].str);
	}

	qsort(data, N, sizeof(Data), compare);

	for (int i = 0; i < N; i++) {
		if (i == 0) printf("%s\n", data[i].str);
		else if (strcmp(data[i - 1].str, data[i].str)) printf("%s\n", data[i].str);
	}			//strcmp 문자열 내용이 같으면 0 반환

	return 0;
}