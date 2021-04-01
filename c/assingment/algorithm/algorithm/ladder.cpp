#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct board_node {
	int start;
	int dest_num;
	int dest;
};

vector< vector< board_node > > ladder;
vector< int > result;
int now;

int find_index(int index, int num) {
	int size = ladder[index].size();

	for (int i = 0; i < size; i++) {
		if (ladder[index][i].start == num) return i;
	}
}

void climbing(int start_num, int dest_num, int dest) {	//0 115 2 45
	int next = find_index(dest_num, dest) + 1;
	
	if (next == ladder[dest_num].size()) { result[dest_num] = now; return; }

	climbing(dest_num, ladder[dest_num][next].dest_num, ladder[dest_num][next].dest);
}

bool compare(board_node a, board_node b) {
	if (a.start < b.start) return false;
	return true;
}

int main() {
	ifstream inp("ladder.inp");
	ofstream out("ladder.out");

	int n, start_num, start, dest_num, dest;

	inp >> n;
	ladder.resize(n);
	result.resize(n);

	while (1) {
		inp >> start_num >> start >> dest_num >> dest;
		if (start_num == 0 && start == 0 && dest_num == 0 && dest == 0) break;

		ladder[start_num].push_back({ start, dest_num, dest });
		ladder[dest_num].push_back({ dest, start_num, start });
	}

	for (int i = 0; i < n; i++) sort(ladder[i].begin(), ladder[i].end(), compare);

	for (int i = 0; i < n; i++) {
		now = i;
		climbing(i, ladder[i][0].dest_num, ladder[i][0].dest);
	}

	int size = result.size();
	for (int i = 0; i < size; i++) out << result[i] << ' ';

	inp.close();
	out.close();
	return 0;
}