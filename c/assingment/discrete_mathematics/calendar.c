#include <stdio.h>
#pragma warning (disable : 4996)

typedef struct Date {
	int year;
	int month;
	int day;
	int week;
	char dayOfTheWeek[3];
}Date;

int dayPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int calculate(Date date) {
	int res = 0;
	int year = date.year - 1;
	int leap = 0;

	for (int i = 4; i <= year; i += 4) {
		if (i % 100 != 0) leap++;
		else { if (i % 400 == 0) leap++; }
	}
	res += leap * 366 + (year - leap) * 365;

	for (int i = 0; i < date.month - 1; i++) {
		if (i != 1) res += dayPerMonth[i];
		else {
			if (date.year % 4 != 0) res += dayPerMonth[i];
			else {
				if(date.year % 100 != 0) res += dayPerMonth[i] + 1;
				else {
					if(date.year % 400 == 0) res += dayPerMonth[i] + 1;
					else res += dayPerMonth[i];
				}
			}
		}
	}
	
	if (dayPerMonth[date.month - 1] == 31) {
		if (date.day > 31) res = -1;
		else res += date.day;
	}
	else if (dayPerMonth[date.month - 1] == 30) {
		if (date.day > 30) res = -1;
		else res += date.day;
	}
	else {
		if (date.year % 4 != 0) {
			if (date.day > 28) res = -1;
			else res += date.day;
		}
		else {
			if (date.year % 100 != 0) {
				if (date.day > 29) res = -1;
				else res += date.day;
			}
			else {
				if (date.year % 400 == 0) {
					if (date.day > 29) res = -1;
					else res += date.day;
				}
				else {
					if (date.day > 28) res = -1;
					else res += date.day;
				}
			}
		}
	}

	return res;
}

int calculate2(Date date) {
	int res = 0, tmp, cnt = 1, day = 1;
	int year = date.year - 1;
	int leap = 0;
	int calendar[6][7] = { 0 };

	for (int i = 4; i <= year; i += 4) {
		if (i % 100 != 0) leap++;
		else { if (i % 400 == 0) leap++; }
	}
	res += leap * 366 + (year - leap) * 365;

	for (int i = 0; i < date.month - 1; i++) {
		if (i != 1) res += dayPerMonth[i];
		else {
			if (date.year % 4 != 0) res += dayPerMonth[i];
			else {
				if (date.year % 100 != 0) res += dayPerMonth[i] + 1;
				else {
					if (date.year % 400 == 0) res += dayPerMonth[i] + 1;
					else res += dayPerMonth[i];
				}
			}
		}
	}
	
	tmp = res % 7 + 1;
	for (int i = 0; i < 6; i++) {
		for (int j = tmp; j < 7; j++) {
			calendar[i][j] = day++;
		}
		tmp = 0;
	}
	
	if (date.dayOfTheWeek[0] == 'M' && date.dayOfTheWeek[1] == 'o') tmp = 1;
	else if (date.dayOfTheWeek[0] == 'T' && date.dayOfTheWeek[1] == 'u') tmp = 2;
	else if (date.dayOfTheWeek[0] == 'W' && date.dayOfTheWeek[1] == 'e') tmp = 3;
	else if (date.dayOfTheWeek[0] == 'T' && date.dayOfTheWeek[1] == 'h') tmp = 4;
	else if (date.dayOfTheWeek[0] == 'F' && date.dayOfTheWeek[1] == 'r') tmp = 5;
	else if (date.dayOfTheWeek[0] == 'S' && date.dayOfTheWeek[1] == 'a') tmp = 6;
	else tmp = 0;

	for (int i = 0;; i++) {
		if (calendar[i][tmp] == 0) continue;
		if (cnt == date.week) { tmp = calendar[i][tmp]; break; }
		cnt++;
	}

	if (dayPerMonth[date.month - 1] == 31) {
		if (tmp > 31) res = -1;
		else res += tmp;
	}
	else if (dayPerMonth[date.month - 1] == 30) {
		if (tmp > 30) res = -1;
		else res += tmp;
	}
	else {
		if (date.year % 4 != 0) {
			if (tmp > 28) res = -1;
			else res += tmp;
		}
		else {
			if (date.year % 100 != 0) {
				if (tmp > 29) res = -1;
				else res += tmp;
			}
			else {
				if (date.year % 400 == 0) {
					if (tmp > 29) res = -1;
					else res += tmp;
				}
				else {
					if (tmp > 28) res = -1;
					else res += tmp;
				}
			}
		}
	}

	return res;
}

int main() {
	FILE *inp = fopen("calendar.inp", "rt");
	FILE *out = fopen("calendar.out", "wt");

	int type, res;
	char bar;
	Date date, date2;

	while (1) {
		fscanf(inp, "%d", &type);
		if (type == -1) break;
		else if (type == 0) {
			fscanf(inp, "%d %c %d %c %d", &date.year, &bar, &date.month, &bar, &date.day);
			fscanf(inp, "%d %c %d %c %d", &date2.year, &bar, &date2.month, &bar, &date2.day);

			res = calculate(date) - calculate(date2);
			if (calculate(date) == -1 || calculate(date2) == -1) fprintf(out, "-1\n");
			else {
				res = calculate(date) - calculate(date2);
				if (res > 0) fprintf(out, "%d\n", res);
				else fprintf(out, "%d\n", res * -1);
			}
		}
		else if (type == 1) {
			fscanf(inp, "%d %c %d %c %d", &date.year, &bar, &date.month, &bar, &date.day);
			fscanf(inp, "%d %c %d %c %d %c %s", &date2.year, &bar, &date2.month, &bar, &date2.week, &bar, date2.dayOfTheWeek);

			if (calculate(date) == -1 || calculate2(date2) == -1) fprintf(out, "-1\n");
			else {
				res = calculate(date) - calculate2(date2);
				if (res > 0) fprintf(out, "%d\n", res);
				else fprintf(out, "%d\n", res * -1);
			}
		}
		else if (type == 2) {
			fscanf(inp, "%d %c %d %c %d %c %s", &date.year, &bar, &date.month, &bar, &date.week, &bar, date.dayOfTheWeek);
			fscanf(inp, "%d %c %d %c %d", &date2.year, &bar, &date2.month, &bar, &date2.day);
			
			if (calculate2(date) == -1 || calculate(date2) == -1) fprintf(out, "-1\n");
			else {
				res = calculate2(date) - calculate(date2);
				if (res > 0) fprintf(out, "%d\n", res);
				else fprintf(out, "%d\n", res * -1);
			}
		}
		else {
			fscanf(inp, "%d %c %d %c %d %c %s", &date.year, &bar, &date.month, &bar, &date.week, &bar, date.dayOfTheWeek);
			fscanf(inp, "%d %c %d %c %d %c %s", &date2.year, &bar, &date2.month, &bar, &date2.week, &bar, date2.dayOfTheWeek);

			if (calculate2(date) == -1 || calculate2(date2) == -1) fprintf(out, "-1\n");
			else {
				res = calculate2(date) - calculate2(date2);
				if (res > 0) fprintf(out, "%d\n", res);
				else fprintf(out, "%d\n", res * -1);
			}
		}
	}

	fclose(inp);
	fclose(out);
	return 0;
}