#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	FILE *inp = fopen("grid2.inp", "rt");
	FILE *out = fopen("grid2.out", "wt");

	int T, N, M, t, s, k;
	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(inp, "%d %d %d %d %d", &N, &M, &t, &s, &k);
		int result, r_mode = 0, c_mode = 0;

		if (t == 3) {
			if (s == 1) {
				result = 0;
				int row = M, column = N - 1;
				for (;;) {
					if (r_mode == c_mode) {//����
						if (r_mode % 2 == 0) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 == 0) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
			else if (s == 2) {
				result = 0;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//����
						if (r_mode % 2 == 1) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 == 0) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
			else if (s == 3) {
				result = N * M + 1;
				int row = M, column = N - 1;
				for (;;) {
					if (r_mode == c_mode) {//����
						if (r_mode % 2 == 1) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 == 1) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
			else {
				result = N * M + 1;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//����
						if (r_mode % 2 == 0) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 == 1) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
		}//t
		else {
			if (s == 1) {
				result = -1 * M + 1;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//����
						if (r_mode % 2 == 0) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 == 0) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
			else if (s == 2) {
				result = M + 1;
				int row = M, column = N - 1;
				for (;;) {
					if (r_mode == c_mode) {//����
						if (r_mode % 2 == 1) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 == 0) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
			else if (s == 3) {
				result = N * M + M;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//����
						if (r_mode % 2 == 1) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 == 1) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
			else {
				result = N * M - M;
				int row = M, column = N - 1;
				for (;;) {
					if (r_mode == c_mode) {//����
						if (r_mode % 2 == 0) {//������
							if (k - row > 0) {//��
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result += k;
								break;
							}
						}
						else {//��
							if (k - row > 0) {//��
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//��
								result -= k;
								break;
							}
						}
					}
					else {//����
						if (c_mode % 2 != 0) {//��
							if (k - column > 0) {//��
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result += M * k;
								break;
							}
						}
						else {//��
							if (k - column > 0) {//��
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//��
								result -= M * k;
								break;
							}//�� ��
						}//�� ��
					}//���� ����
				}//for
			}//s
		}//t

		fprintf(out, "%d", result);

		if (i != T - 1) fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}