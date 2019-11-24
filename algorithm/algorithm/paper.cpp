#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct board_node {
	int num;

	int w_start;
	int h_start;
	int w_dest;
	int h_dest;

	int x;
	int y;
	int w;
	int h;
	int area;
};

vector< board_node > input;
int board[4001][4001];
vector< vector< int > > shape(2);
int overlap, not_overlap, part_overlap;

void overlap_check(int index) {
	int cnt = 0;
	for (int i = input[index].x; i < input[index].w; i++) {
		for (int j = input[index].y; j < input[index].h; j++) {
			if (board[i][j] == input[index].num + 1) cnt++;
		}
	}

	if (cnt == input[index].area) not_overlap++;
	else if (cnt == 0) overlap++;
	else part_overlap++;
}

void overlaping() {
	int size = input.size();
	for (int i = 0; i < size; i++) {
		for (int j = input[i].x; j < input[i].w; j++) {
			for (int k = input[i].y; k < input[i].h; k++) {
				board[j][k] = input[i].num + 1;
				input[i].area++;
			}
		}
	}

	for (int i = 0; i < size; i++) overlap_check(i);
}

void mapping() {
	int size = input.size(), x_size = shape[0].size(), y_size = shape[1].size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < x_size; j++) {
			if (input[i].w_start == shape[0][j]) input[i].x = j;
			if (input[i].w_dest == shape[0][j]) input[i].w = j;
		}

		for (int j = 0; j < y_size; j++) {
			if (input[i].h_start == shape[1][j]) input[i].y = j;
			if (input[i].h_dest == shape[1][j]) input[i].h = j;
		}
	}

	overlaping();
}

bool check(int p, int num) {
	int size = shape[p].size();
	for (int i = 0; i < size; i++) {
		if (num == shape[p][i]) return false;
	}

	return true;
}

bool compare(int a, int b) {
	if (a > b) return false;
	return true;
}

int main() {
	ifstream inp("paper.inp");
	ofstream out("paper.out");

	int n, x, y, w, h;

	inp >> n;
	for(int i = 0, j = 0, k = 0; i < n; i++) {
		inp >> x >> y >> w >> h;
		input.push_back({ i, x, y, x + w, y + h });
		if (check(0, x)) { shape[0].push_back(x); j++; }
		if (check(0, x + w)) { shape[0].push_back(x + w); j++; }
		if (check(1, y)) { shape[1].push_back(y); k++; }
		if (check(1, y + h)) { shape[1].push_back(y + h); k++; }
	}

	sort(shape[0].begin(), shape[0].end(), compare);
	sort(shape[1].begin(), shape[1].end(), compare);

	mapping();

	out << overlap << ' ' << part_overlap << ' ' << not_overlap;

	inp.close();
	out.close();
	return 0;
}