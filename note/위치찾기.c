#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int Search(int *arr, int num) {	//num이 몇번째인지 찾는 함수
	for (int i = 0; i < _msize(arr) / sizeof(int); i++) {
		if (arr[i] == num)
			return i + 1;
	}
	return -1;		//배열에 찾는 수가 없음
}

int main() {
	int num;		//배열에서 찾아 볼 수
	int L;			//배열 길이

	scanf("%d", &L);
	int *arr = (int *)malloc(sizeof(int) * L);		//동적할당

	for (int i = 0; i < L; i++)
		scanf("%d", arr + i);

	scanf("%d", &num);

	printf("%d\n", Search(arr, num));

	free(arr);
	return 0;
}

/*int main() {
int a;
scanf("%d", &a);
int *arr = (int *)malloc(sizeof(int) * a);

printf("%d\n", _msize(arr));		//_msize(arr) == 힙에 할당된 메모리의 크기

free(arr);
return 0;
}*/