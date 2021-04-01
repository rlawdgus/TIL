#include <iostream>
using namespace std;

void product(int tmp[15], int num) {	//2진수로 변환
	if (num < 0) num *= -1;	//음수일 경우 변환을 위해 부호를 바꿈

	for (int i = 0; i < 8; i++) tmp[i] = 0;	//앞 부분 0으로 채움

	for (int i = 8, j = 64; i < 15; i++, j /= 2) {
		if (num >= j) { tmp[i] = 1; num -= j; }
		else tmp[i] = 0;
	}
}

void complement_2(int tmp[15], int num) {	//2의 보수
	if (num >= 0) product(tmp, num);
	else {
		product(tmp, num);

		for (int i = 0; i < 15; i++) {
			if (tmp[i] == 0) tmp[i] = 1;
			else tmp[i] = 0;
		}

		if (tmp[14] == 0) tmp[14] = 1;	//1 더해준다
		else {
			for (int i = 14; i >= 0; i--) {
				if (tmp[i] == 0) { tmp[i] = 1; break; }
				tmp[i] = 0;
			}
		}	//여기까지가 2의보수
	}
}

void sub_complement(int tmp[15]) {	//뺄셈 양수 == 덧셈 음수
	for (int i = 0; i < 15; i++) {
		if (tmp[i] == 0) tmp[i] = 1;
		else tmp[i] = 0;
	}

	if (tmp[14] == 0) tmp[14] = 1;	//1 더해준다
	else {
		for (int i = 14; i >= 0; i--) {
			if (tmp[i] == 0) { tmp[i] = 1; break; }
			tmp[i] = 0;
		}
	}	//여기까지가 2의보수
}

void shift_R(int num[15]) {	//오른쪽으로 시프트
	for (int i = 14; i > 0; i--) num[i] = num[i - 1];
	num[0] = 0;
}

void shift_L(int num[15]) {	//왼쪽으로 시프트
	for (int i = 0; i < 14; i++) num[i] = num[i + 1];
	num[14] = 0;
}

void add(int result[15], int tmp[15]) {	//덧셈연산	(result + tmp)
	int carry = 0;

	for (int i = 14; i >= 0; i--) {
		if (result[i] + tmp[i] + carry == 0) { result[i] = 0; carry = 0; }
		else if (result[i] + tmp[i] + carry == 1) { result[i] = 1; carry = 0; }
		else if (result[i] + tmp[i] + carry == 2) { result[i] = 0; carry = 1; }
		else { result[i] = 1; carry = 1; }
	}
}

void sub(int result[15], int tmp[15]) {	//뺄셈 연산	(result - tmp)
	int tmp_copy[15];
	for (int i = 1; i < 15; i++) tmp_copy[i] = tmp[i];
	sub_complement(tmp_copy);
	add(result, tmp_copy);
}

void multiple_2(int result[15], int tmp[15], int tmp2[15]) {	//곱셈 알고리즘 2
	for (int i = 0; i < 7; i++) shift_L(tmp);	//피승수 7비트 만큼 시프트
	for (int i = 0; i < 15; i++) result[i] = 0;	//누적곱 초기화

	for (int i = 14; i > 7; i--) {	//승수를 보면서 연산
		if (tmp2[i] == 0) shift_R(result);
		else { add(result, tmp); shift_R(result); }
	}
}

void booth(int result[15], int tmp[15], int tmp2[15]) {	//부스 알고리즘
	shift_L(tmp2);	//승수 추가비트
	for (int i = 0; i < 15; i++) result[i] = 0;	//누적곱 초기화

	for (int i = 14; i > 6; i--) {		//승수 보면서 연산표대로 연산, 승수는 비트 추가 후 8자리(7 ~ 14)
		if (tmp2[i - 1] == 0 && tmp2[i] == 0) shift_L(tmp);
		else if (tmp2[i - 1] == 0 && tmp2[i] == 1) { add(result, tmp); shift_L(tmp); }
		else if (tmp2[i - 1] == 1 && tmp2[i] == 0) { sub(result, tmp); shift_L(tmp); }
		else shift_L(tmp);
	}
}

void Print(int tmp[], int sign) {	//결과 출력
	if (sign == 1) tmp[0] = 0;
	else tmp[0] = 1;
	for (int i = 0; i < 15; i++) cout << tmp[i];
}

int main() {
	int num, num2, sign;	//num : 피승수, num2 : 승수
	int tmp[15], tmp2[15], result[15];		//0번 인덱스는 부호

	cout << " 128 128입력시 종료\n\n";
	while (1) {
		cout << "두 수 입력 : ";
		cin >> num >> num2;
		if (num == 128 && num2 == 128) return 0;
		if (num > 127 || num < -127 || num2 > 127 || num2 < -127) { cout << "! 오버플로우 발생\n\n"; continue; }

		if (num * num2 >= 0) sign = 1;
		else sign = -1;

		product(tmp, num), product(tmp2, num2);	//num, num2 2진수 변환
		multiple_2(result, tmp, tmp2);	//result에 결과 저장

		cout << "*첫 비트는 부호, 나머지 14비트가 수 부분" << '\n';
		cout << "\n곱셈 알고리즘2 결과(부호화 크기) : ";
		Print(result, sign);	//비트 수 15 (맨 앞 비트는 부호역할만)
		cout << '\n';

		//----------------------------------------------------------------------------------------
		complement_2(tmp, num), complement_2(tmp2, num2);	//num, num2 2의 보수
		booth(result, tmp, tmp2);	//result에 결과 저장

		cout << "\nbooth 알고리즘 결과(2의 보수) : ";
		Print(result, sign);	//첫번째 비트가 부호 비트
		cout << "\n\n\n";
	}
}