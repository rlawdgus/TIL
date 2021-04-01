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

bool compare(process &a, process &b) {
	if (a.dest == b.dest) return a.number < b.number;
	return a.dest < b.dest;
}

int run() {
	int result = 0, waiting = 0;

	for (int i = 0; i < input.size() - 1; i++) {
		waiting += input[i].burst;
		if (waiting > input[i + 1].dest) result += (waiting - input[i + 1].dest);
		else waiting = input[i + 1].dest;
	}

	return result;
}

int main() {
	ifstream inp("fcfs.inp");
	ofstream out("fcfs.out");

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

	out << run();

	return 0;
}