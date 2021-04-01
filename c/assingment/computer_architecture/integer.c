#include <stdio.h>
#pragma warning (disable : 4996)

typedef struct Base {
	char num[9];
	int weight[8];		//����ġ
}Base;

void signMagnitude(Base base) {
	int result = 0;

	printf("1) ��ȣȭ ũ��\n");
	printf("    2���� ǥ�� : ");

	if (base.num[0] == '0') {//���
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2���� ���
			if (base.num[i] == '1') result += base.weight[i];	//10���� ��ȯ
		}
		printf("\n");
	}
	else {//����
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2���� ���
			if (base.num[i] == '1' && i != 0) result += base.weight[i];	//10���� ��ȯ(ù°�ڸ��� ��ȯ���� �ʴ´�)
		}
		result *= -1;
		printf("\n");
	}
	
	printf("    10���� ǥ�� : %d\n\n", result);
}

void complement_1(Base base) {
	int result = 0;

	printf("2) 1�� ����\n");
	printf("    �Է°��� 1�� ���� ���ϸ� ");

	if (base.num[0] == '0') {//���
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2���� ���
			if (base.num[i] == '1') result += base.weight[i];	//10���� ��ȯ
		}
		printf("\n");
	}
	else {//����
		for (int i = 0; i < 8; i++) {
			if (base.num[i] == '0') printf("1");	//0�� 1�� ���
			else printf("0");						//1�� 0���� ���

			if (base.num[i] == '0') result += base.weight[i];	//10���� ��ȯ(1�� 0���� �ٲٴϱ� 0���� ��ȯ)
		}
		result *= -1;//������

		printf("\n");
	}

	printf("    10���� ǥ�� : %d\n\n", result);
}

void complement_2(Base base) {
	int result = 0;

	printf("3) 2�� ����\n");
	printf("    �Է°��� 2�� ���� ���ϸ� ");

	if (base.num[0] == '0') {//���
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2���� ���
			if (base.num[i] == '1') result += base.weight[i];	//10���� ��ȯ
		}
		printf("\n");
	}
	else {//����
		char tmp[8], index = 7;
		for (int i = 0; i < 8; i++) {
			if (base.num[i] == '0') tmp[i] = '1';	//0�� 1�� �ٲ�
			else tmp[i] = '0';						//1�� 0���� �ٲ�

			if (base.num[i] == '0') result += base.weight[i];	//10���� ��ȯ(1�� 0���� �ٲٴϱ� 0���� ��ȯ)
		}
		result++;	//2�� ����
		result *= -1;//������

		if (tmp[index] == '0') {
			tmp[index] = '1';	//1 ����
			for (int i = 0; i < 8; i++) printf("%c", tmp[i]);
		}
		else {
			while (1) {
				tmp[index--] = '0';	//1 ���ϰ� �ø��� �߻�

				if (tmp[index] == '0') { tmp[index] = '1'; break; } //���� �ڸ����� 0�̸� �ø��� �����ְ� ����
			}

			for (int i = 0; i < 8; i++) printf("%c", tmp[i]);	//2�� ������ 2���� ���
		}
		
		printf("\n");
	}

	printf("    10���� ǥ�� : %d\n\n", result);
}

int inputCheck(Base base) {
	for (int i = 0;; i++) {
		if (base.num[i] != '0' && base.num[i] != '1' && base.num[i] != '\n') { printf("2���� �Է��� �ƴմϴ�.\n"); return 0; }
		if (base.num[i] == '\n') {
			if (i != 8) { printf("8��Ʈ �Է��� �ƴմϴ�.\n"); return 0; }
			else return 1;
		}
	}
}

int main() {
	Base input;

	printf("�Է°� : ");
	for (int i = 7, j = 1; i >= 0; i--, j *= 2) input.weight[i] = j;	//�ڸ����� ����ġ �ʱ�ȭ
	for (int i = 0;; i++) {
		scanf("%c", &input.num[i]);	//�Է�
			
		if (input.num[i] == '\n') break;
	}

	if (inputCheck(input)) {
		signMagnitude(input);
		complement_1(input);
		complement_2(input);
	}

	return 0;
}