#include <fstream>
using namespace std;

//0:top, 1:front, 2:bottom, 3:right, 4:back, 5:left;
enum {
	TOP,
	FRONT,
	BOTTOM,
	RIGHT,
	BACK,
	LEFT
};

void Roll(int dice[], int cnt) {	//아래로
	while (cnt--) {
		int tmp;
		tmp = dice[TOP];
		dice[TOP] = dice[BACK];
		dice[BACK] = dice[BOTTOM];
		dice[BOTTOM] = dice[FRONT];
		dice[FRONT] = tmp;
	}
}

void Rotate(int dice[], int cnt) {	//오른쪽으로
	while (cnt--) {
		int tmp;
		tmp = dice[FRONT];
		dice[FRONT] = dice[RIGHT];
		dice[RIGHT] = dice[BACK];
		dice[BACK] = dice[LEFT];
		dice[LEFT] = tmp;
	}
}

void Dice(int dice[], char roll[], int *x, int *y, int length) {
	for (int i = 0; i < length; i++) {
		if (roll[i] == 'N') {
			(*x)++;
			Roll(dice, 3);
		}
		else if (roll[i] == 'S') {
			(*x)--;
			Roll(dice, 1);
		}
		else if (roll[i] == 'E') {
			(*y)++;
			Rotate(dice, 1);
			Roll(dice, 1);
			Rotate(dice, 3);
		}
		else {
			(*y)--;
			Rotate(dice, 3);
			Roll(dice, 1);
			Rotate(dice, 1);
		}
	}
}

void Setting(int dice[], int position[]) {
	int cnt = 0;

	while(1) {
		if (dice[TOP] == position[TOP] && dice[FRONT] == position[FRONT]) return;

		if (dice[TOP] == position[TOP]) Rotate(dice, 1);
		else if (dice[FRONT] == position[TOP]) Roll(dice, 3);
		else if (cnt == 3) { Roll(dice, 1); cnt = 0; }
		else { Rotate(dice, 1); cnt++; }
	}
}

int main() {
	ifstream inp("die.inp");
	ofstream out("die.out");

	int T, N;
	int dice[6], position[2];
	char roll[1000];
	int x = 0, y = 0;

	inp >> T;
	while (T--) {
		for (int i = 0; i < 6; i++) inp >> dice[i];
		for (int i = 0; i < 2; i++) inp >> position[i];
		Setting(dice, position);

		inp >> N;
		for (int i = 0; i < N; i++) inp >> roll[i];
		Dice(dice, roll, &x, &y, N);

		out << y << ' ' << x << ' ' << dice[TOP] << ' ' << dice[FRONT] << '\n';
		x = 0, y = 0;
	}

	inp.close();
	out.close();
	return 0;
}