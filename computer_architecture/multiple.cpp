#include <iostream>
using namespace std;

void product(int tmp[15], int num) {	//2������ ��ȯ
	if (num < 0) num *= -1;	//������ ��� ��ȯ�� ���� ��ȣ�� �ٲ�

	for (int i = 0; i < 8; i++) tmp[i] = 0;	//�� �κ� 0���� ä��

	for (int i = 8, j = 64; i < 15; i++, j /= 2) {
		if (num >= j) { tmp[i] = 1; num -= j; }
		else tmp[i] = 0;
	}
}

void complement_2(int tmp[15], int num) {	//2�� ����
	if (num >= 0) product(tmp, num);
	else {
		product(tmp, num);

		for (int i = 0; i < 15; i++) {
			if (tmp[i] == 0) tmp[i] = 1;
			else tmp[i] = 0;
		}

		if (tmp[14] == 0) tmp[14] = 1;	//1 �����ش�
		else {
			for (int i = 14; i >= 0; i--) {
				if (tmp[i] == 0) { tmp[i] = 1; break; }
				tmp[i] = 0;
			}
		}	//��������� 2�Ǻ���
	}
}

void sub_complement(int tmp[15]) {	//���� ��� == ���� ����
	for (int i = 0; i < 15; i++) {
		if (tmp[i] == 0) tmp[i] = 1;
		else tmp[i] = 0;
	}

	if (tmp[14] == 0) tmp[14] = 1;	//1 �����ش�
	else {
		for (int i = 14; i >= 0; i--) {
			if (tmp[i] == 0) { tmp[i] = 1; break; }
			tmp[i] = 0;
		}
	}	//��������� 2�Ǻ���
}

void shift_R(int num[15]) {	//���������� ����Ʈ
	for (int i = 14; i > 0; i--) num[i] = num[i - 1];
	num[0] = 0;
}

void shift_L(int num[15]) {	//�������� ����Ʈ
	for (int i = 0; i < 14; i++) num[i] = num[i + 1];
	num[14] = 0;
}

void add(int result[15], int tmp[15]) {	//��������	(result + tmp)
	int carry = 0;

	for (int i = 14; i >= 0; i--) {
		if (result[i] + tmp[i] + carry == 0) { result[i] = 0; carry = 0; }
		else if (result[i] + tmp[i] + carry == 1) { result[i] = 1; carry = 0; }
		else if (result[i] + tmp[i] + carry == 2) { result[i] = 0; carry = 1; }
		else { result[i] = 1; carry = 1; }
	}
}

void sub(int result[15], int tmp[15]) {	//���� ����	(result - tmp)
	int tmp_copy[15];
	for (int i = 1; i < 15; i++) tmp_copy[i] = tmp[i];
	sub_complement(tmp_copy);
	add(result, tmp_copy);
}

void multiple_2(int result[15], int tmp[15], int tmp2[15]) {	//���� �˰��� 2
	for (int i = 0; i < 7; i++) shift_L(tmp);	//�ǽ¼� 7��Ʈ ��ŭ ����Ʈ
	for (int i = 0; i < 15; i++) result[i] = 0;	//������ �ʱ�ȭ

	for (int i = 14; i > 7; i--) {	//�¼��� ���鼭 ����
		if (tmp2[i] == 0) shift_R(result);
		else { add(result, tmp); shift_R(result); }
	}
}

void booth(int result[15], int tmp[15], int tmp2[15]) {	//�ν� �˰���
	shift_L(tmp2);	//�¼� �߰���Ʈ
	for (int i = 0; i < 15; i++) result[i] = 0;	//������ �ʱ�ȭ

	for (int i = 14; i > 6; i--) {		//�¼� ���鼭 ����ǥ��� ����, �¼��� ��Ʈ �߰� �� 8�ڸ�(7 ~ 14)
		if (tmp2[i - 1] == 0 && tmp2[i] == 0) shift_L(tmp);
		else if (tmp2[i - 1] == 0 && tmp2[i] == 1) { add(result, tmp); shift_L(tmp); }
		else if (tmp2[i - 1] == 1 && tmp2[i] == 0) { sub(result, tmp); shift_L(tmp); }
		else shift_L(tmp);
	}
}

void Print(int tmp[], int sign) {	//��� ���
	if (sign == 1) tmp[0] = 0;
	else tmp[0] = 1;
	for (int i = 0; i < 15; i++) cout << tmp[i];
}

int main() {
	int num, num2, sign;	//num : �ǽ¼�, num2 : �¼�
	int tmp[15], tmp2[15], result[15];		//0�� �ε����� ��ȣ

	cout << " 128 128�Է½� ����\n\n";
	while (1) {
		cout << "�� �� �Է� : ";
		cin >> num >> num2;
		if (num == 128 && num2 == 128) return 0;
		if (num > 127 || num < -127 || num2 > 127 || num2 < -127) { cout << "! �����÷ο� �߻�\n\n"; continue; }

		if (num * num2 >= 0) sign = 1;
		else sign = -1;

		product(tmp, num), product(tmp2, num2);	//num, num2 2���� ��ȯ
		multiple_2(result, tmp, tmp2);	//result�� ��� ����

		cout << "*ù ��Ʈ�� ��ȣ, ������ 14��Ʈ�� �� �κ�" << '\n';
		cout << "\n���� �˰���2 ���(��ȣȭ ũ��) : ";
		Print(result, sign);	//��Ʈ �� 15 (�� �� ��Ʈ�� ��ȣ���Ҹ�)
		cout << '\n';

		//----------------------------------------------------------------------------------------
		complement_2(tmp, num), complement_2(tmp2, num2);	//num, num2 2�� ����
		booth(result, tmp, tmp2);	//result�� ��� ����

		cout << "\nbooth �˰��� ���(2�� ����) : ";
		Print(result, sign);	//ù��° ��Ʈ�� ��ȣ ��Ʈ
		cout << "\n\n\n";
	}
}