#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct process {
	int number;
	int dest;
	int burst;
}process;

vector< process > input;
int result = 0, waiting = 0;
int cnt = 0;

bool compare(process &a, process &b) {
	if (a.dest == b.dest) return a.number < b.number;
	return a.dest < b.dest;
}

bool burst_compare(process &a, process &b) {
	if (a.burst == b.burst) return a.number < b.number;
	return a.burst < b.burst;
}

void run() {
	waiting += input[0].burst;
	input.erase(input.begin());

	for (int i = 0;; i++) {
		if (i == input.size()) break;
		if (input[i].dest > waiting) break;
		cnt++;
	}

	sort(input.begin(), input.begin() + cnt, burst_compare);
	if(input[0].dest < waiting) result += (waiting - input[0].dest);
	else waiting = input[0].dest;

	if (input.size() != 1) { cnt = 0; run(); }
}

int main() {
	ifstream inp("sjf.inp");
	ofstream out("sjf.out");

	int n, num, de, bu;

	inp >> n;
	while (n--) {
		inp >> num >> de >> bu;

		process node;
		node.number = num;
		node.dest = de;
		node.burst = bu;

		input.push_back(node);
	}

	sort(input.begin(), input.end(), compare);

	run();
	out << result;

	return 0;
}