#include <fstream>
#include <vector>
#include <algorithm>
#define INF 2147438647
using namespace std;

typedef struct process {
	int number;
	int dest;
	int burst;
}process;

vector< process > input;
int result = 0;

bool compare(process &a, process &b) {
	if (a.dest == b.dest) return a.number < b.number;
	return a.dest < b.dest;
}

bool burst_compare(process &a, process &b) {
	if (a.burst == b.burst) return a.number < b.number;
	return a.burst < b.burst;
}

void run() {
	vector< process > tmp;
	int cnt = 0;
	for (int i = 0; input[i].dest == 0; i++) {
		tmp.push_back(input[0]);
		cnt++;
	}

	for (int running = 0;;) {
		if (tmp.empty() && cnt == input.size() - 1) return;	//모든 프로세스 끝

		running++;	//달린거리

		if (!tmp.empty()) {
			tmp[0].burst--;	//1씩 뺀다
			result += (tmp.size() - 1);	//wait 계산
			if (tmp[0].burst == 0) tmp.erase(tmp.begin());	//프로세스 하나 끝
		}

		if (running == input[cnt].dest) {	//도착시점
			while (running == input[cnt].dest) {
				tmp.push_back(input[cnt]); //도착한 프로세스 대기
				cnt++;
			}
			sort(tmp.begin(), tmp.end(), burst_compare);
		}
	}
}

int main() {
	ifstream inp("srtf.inp");
	ofstream out("srtf.out");

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

	process node;
	node.number = INF;
	node.dest = INF;
	node.burst = INF;

	input.push_back(node);

	sort(input.begin(), input.end(), compare);

	run();
	out << result;

	return 0;
}