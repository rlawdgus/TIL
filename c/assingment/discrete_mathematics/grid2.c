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
					if (r_mode == c_mode) {//°¡·Î
						if (r_mode % 2 == 0) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 == 0) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
				}//for
			}//s
			else if (s == 2) {
				result = 0;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//°¡·Î
						if (r_mode % 2 == 1) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 == 0) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
				}//for
			}//s
			else if (s == 3) {
				result = N * M + 1;
				int row = M, column = N - 1;
				for (;;) {
					if (r_mode == c_mode) {//°¡·Î
						if (r_mode % 2 == 1) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 == 1) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
				}//for
			}//s
			else {
				result = N * M + 1;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//°¡·Î
						if (r_mode % 2 == 0) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 == 1) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
				}//for
			}//s
		}//t
		else {
			if (s == 1) {
				result = -1 * M + 1;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//°¡·Î
						if (r_mode % 2 == 0) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 == 0) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
				}//for
			}//s
			else if (s == 2) {
				result = M + 1;
				int row = M, column = N - 1;
				for (;;) {
					if (r_mode == c_mode) {//°¡·Î
						if (r_mode % 2 == 1) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 == 0) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
				}//for
			}//s
			else if (s == 3) {
				result = N * M + M;
				int row = M - 1, column = N;
				for (;;) {
					if (r_mode != c_mode) {//°¡·Î
						if (r_mode % 2 == 1) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 == 1) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
				}//for
			}//s
			else {
				result = N * M - M;
				int row = M, column = N - 1;
				for (;;) {
					if (r_mode == c_mode) {//°¡·Î
						if (r_mode % 2 == 0) {//¿À¸¥ÂÊ
							if (k - row > 0) {//´Ù
								result += row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result += k;
								break;
							}
						}
						else {//¿Þ
							if (k - row > 0) {//´Ù
								result -= row;
								k -= row;
								row--;
								r_mode++;
							}
							else {//´ú
								result -= k;
								break;
							}
						}
					}
					else {//¼¼·Î
						if (c_mode % 2 != 0) {//ÇÏ
							if (k - column > 0) {//´Ù
								result += M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result += M * k;
								break;
							}
						}
						else {//»ó
							if (k - column > 0) {//´Ù
								result -= M * column;
								k -= column;
								column--;
								c_mode++;
							}
							else {//´ú
								result -= M * k;
								break;
							}//´Ù ´ú
						}//»ó ÇÏ
					}//°¡·Î ¼¼·Î
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