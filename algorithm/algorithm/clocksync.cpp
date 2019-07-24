#include <fstream>
#include <vector>
#define INF 2147483646
#define SWITCH 10
#define CLOCK 16
using namespace std;

int linked[SWITCH][CLOCK] = {
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};


void Push(vector<int> &clock, int swtch) {
	for (int i = 0; i < CLOCK; i++) {
		if (linked[swtch][i] == 1)
			clock[i] += 3;
		if (clock[i] == 15)
			clock[i] = 3;
	}
}

bool areAligned(const vector<int> & clocks) {
	for (int i = 0; i < CLOCK; i++)
		if (clocks[i] != 12)
			return false;
	return true;
}


int minClick(vector<int> &clock, int swtch) {
	if (swtch == SWITCH) return areAligned(clock) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		int tmp = cnt + minClick(clock, swtch + 1);
		ret = ret < tmp ? ret : tmp;
		Push(clock, swtch);
	}
	return ret;
}

int main() {
	ifstream inp("clocksync.inp");
	ofstream out("clocksync.out");

	int C;
	vector< int > clock(16);

	inp >> C;
	while (C--) {
		for (int i = 0; i < 16; i++) inp >> clock[i];

		out << minClick(clock, 0) << '\n';
	}

	inp.close();
	out.close();
	return 0;
}