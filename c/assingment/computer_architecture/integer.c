#include <stdio.h>
#pragma warning (disable : 4996)

typedef struct Base {
	char num[9];
	int weight[8];		//가중치
}Base;

void signMagnitude(Base base) {
	int result = 0;

	printf("1) 부호화 크기\n");
	printf("    2진수 표현 : ");

	if (base.num[0] == '0') {//양수
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2진수 출력
			if (base.num[i] == '1') result += base.weight[i];	//10진수 변환
		}
		printf("\n");
	}
	else {//음수
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2진수 출력
			if (base.num[i] == '1' && i != 0) result += base.weight[i];	//10진수 변환(첫째자리는 변환하지 않는다)
		}
		result *= -1;
		printf("\n");
	}
	
	printf("    10진수 표현 : %d\n\n", result);
}

void complement_1(Base base) {
	int result = 0;

	printf("2) 1의 보수\n");
	printf("    입력값을 1의 보수 취하면 ");

	if (base.num[0] == '0') {//양수
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2진수 출력
			if (base.num[i] == '1') result += base.weight[i];	//10진수 변환
		}
		printf("\n");
	}
	else {//음수
		for (int i = 0; i < 8; i++) {
			if (base.num[i] == '0') printf("1");	//0은 1로 출력
			else printf("0");						//1은 0으로 출력

			if (base.num[i] == '0') result += base.weight[i];	//10진수 변환(1을 0으로 바꾸니까 0에서 변환)
		}
		result *= -1;//음수로

		printf("\n");
	}

	printf("    10진수 표현 : %d\n\n", result);
}

void complement_2(Base base) {
	int result = 0;

	printf("3) 2의 보수\n");
	printf("    입력값을 2의 보수 취하면 ");

	if (base.num[0] == '0') {//양수
		for (int i = 0; i < 8; i++) {
			printf("%c", base.num[i]);		//2진수 출력
			if (base.num[i] == '1') result += base.weight[i];	//10진수 변환
		}
		printf("\n");
	}
	else {//음수
		char tmp[8], index = 7;
		for (int i = 0; i < 8; i++) {
			if (base.num[i] == '0') tmp[i] = '1';	//0은 1로 바꿈
			else tmp[i] = '0';						//1은 0으로 바꿈

			if (base.num[i] == '0') result += base.weight[i];	//10진수 변환(1을 0으로 바꾸니까 0에서 변환)
		}
		result++;	//2의 보수
		result *= -1;//음수로

		if (tmp[index] == '0') {
			tmp[index] = '1';	//1 더함
			for (int i = 0; i < 8; i++) printf("%c", tmp[i]);
		}
		else {
			while (1) {
				tmp[index--] = '0';	//1 더하고 올림수 발생

				if (tmp[index] == '0') { tmp[index] = '1'; break; } //다음 자리수가 0이면 올림수 더해주고 정지
			}

			for (int i = 0; i < 8; i++) printf("%c", tmp[i]);	//2의 보수된 2진수 출력
		}
		
		printf("\n");
	}

	printf("    10진수 표현 : %d\n\n", result);
}

int inputCheck(Base base) {
	for (int i = 0;; i++) {
		if (base.num[i] != '0' && base.num[i] != '1' && base.num[i] != '\n') { printf("2진수 입력이 아닙니다.\n"); return 0; }
		if (base.num[i] == '\n') {
			if (i != 8) { printf("8비트 입력이 아닙니다.\n"); return 0; }
			else return 1;
		}
	}
}

int main() {
	Base input;

	printf("입력값 : ");
	for (int i = 7, j = 1; i >= 0; i--, j *= 2) input.weight[i] = j;	//자리마다 가중치 초기화
	for (int i = 0;; i++) {
		scanf("%c", &input.num[i]);	//입력
			
		if (input.num[i] == '\n') break;
	}

	if (inputCheck(input)) {
		signMagnitude(input);
		complement_1(input);
		complement_2(input);
	}

	return 0;
}