#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int Search(int *arr, int num) {	//num�� ���°���� ã�� �Լ�
	for (int i = 0; i < _msize(arr) / sizeof(int); i++) {
		if (arr[i] == num)
			return i + 1;
	}
	return -1;		//�迭�� ã�� ���� ����
}

int main() {
	int num;		//�迭���� ã�� �� ��
	int L;			//�迭 ����

	scanf("%d", &L);
	int *arr = (int *)malloc(sizeof(int) * L);		//�����Ҵ�

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

printf("%d\n", _msize(arr));		//_msize(arr) == ���� �Ҵ�� �޸��� ũ��

free(arr);
return 0;
}*/