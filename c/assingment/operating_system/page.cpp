#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct input_node {
	int pid;
	int pnum;
};

struct location_node {
	vector< int > pnum;
	vector< int > loc;
};

struct tmp_node {
	int index;
	int pid;
	int pnum;
};

ifstream inp("page.inp");
ofstream out("page.out");

int k, fault = 0;

vector< input_node > input;
vector< input_node > input;
vector< location_node > location(10500);

void print() {	//출력
	for (int i = 0; i < input.size(); i++) out << i << ' ' << input[i].pid << ' ' << input[i].pnum << '\n';
}

void restore() {
	print();
	location.clear();
	location.resize(10500);
	fault = 0;
	input.clear();
}

bool compare(tmp_node a, tmp_node b) {
	return a.index > b.index;
}

bool check_board_pid(int pid) {	//board에 지금 들어가는 pid가 있는지 확인 있으면 true
	for (int i = 0; i < input.size(); i++) if (pid == input[i].pid) return true;
	return false;
}

bool check_board_pnum(int pid, int pnum) {	//board에 있는 pid가 pnum도 같을 때 true
	int cycle = location[pid].loc.size();
	for (int i = 0; i < cycle; i++) {
		if (pnum == location[pid].pnum[i]) return true;
	}
	return false;
}

void add_node(int index) {
	input.push_back(input[index]);
	fault++;

	location_node node;
	location[input[index].pid].pnum.push_back(input[index].pnum);
	location[input[index].pid].loc.push_back(input.size() - 1);	//그때의 인덱스
}

void update(int i, int l_index) {
	location[input[i].pid].pnum.push_back(input[i].pnum);
	location[input[i].pid].pnum.erase(location[input[i].pid].pnum.begin() + l_index, location[input[i].pid].pnum.begin() + l_index + 1);

	location[input[i].pid].loc.push_back(location[input[i].pid].loc[l_index]);
	location[input[i].pid].loc.erase(location[input[i].pid].loc.begin() + l_index, location[input[i].pid].loc.begin() + l_index + 1);
}

void fifo() {
	for (int i = 0; i < input.size(); i++) {	//현재: input[i]
		if (check_board_pid(input[i].pid)) {	//board에 지금 들어가는 pid가 있을 때
			if (check_board_pnum(input[i].pid, input[i].pnum)) continue;	//pnum까지 일치할 때

			if (location[input[i].pid].loc.size() < k) add_node(i);	//자리가 있을 때
			else {	//자리가 없을 때
				input[location[input[i].pid].loc[0]] = input[i];
				fault++;

				update(i, 0);
			}
		}
		else add_node(i);
	}
}

void lru() {
	for (int i = 0; i < input.size(); i++) {	//현재: input[i]
		if (check_board_pid(input[i].pid)) {	//board에 지금 들어가는 pid가 있을 때
			if (check_board_pnum(input[i].pid, input[i].pnum)) {	//pnum까지 일치할 때
				int cycle = location[input[i].pid].loc.size();
				int j = 0;
				for (; j < cycle; j++) {
					if (input[location[input[i].pid].loc[j]].pnum == input[i].pnum) {
						update(i, j);
						break;
					}
				}
				continue;
			}

			if (location[input[i].pid].loc.size() < k) add_node(i);	//자리가 있을 때
			else {	//자리가 없을 때
				input[location[input[i].pid].loc[0]] = input[i];
				fault++;

				update(i, 0);
			}
		}
		else add_node(i);
	}
}

void opt() {
	for (int i = 0; i < input.size(); i++) {	//현재: input[i]
		if (check_board_pid(input[i].pid)) {	//board에 지금 들어가는 pid가 있을 때
			if (check_board_pnum(input[i].pid, input[i].pnum)) continue;	//pnum까지 일치할 때

			if (location[input[i].pid].loc.size() < k) add_node(i);	//자리가 있을 때
			else {	//자리가 없을 때
				vector< tmp_node > tmp;
				int l_cycle = location[input[i].pid].loc.size(), i_cycle = input.size();

				for (int l_index = 0; l_index < l_cycle; l_index++) {	//location index
					for (int i_index = i + 1; i_index < i_cycle; i_index++) {	//input index
						if (input[location[input[i].pid].loc[l_index]].pid == input[i_index].pid) {
							if (location[input[i].pid].pnum[l_index] == input[i_index].pnum) {
								tmp.push_back({ i_index, input[i_index].pid, input[i_index].pnum });
								break;
							}
						}
					}
				}
				sort(tmp.begin(), tmp.end(), compare);

				if (tmp.size() == k) {	//다 있는경우
					fault++;

					int l_cycle = location[input[i].pid].loc.size();
					int j = 0;
					for (; j < l_cycle; j++) {
						if (input[location[input[i].pid].loc[j]].pnum == tmp[0].pnum) {
							input[location[input[i].pid].loc[j]] = input[i];
							update(i, j);
							break;
						}
					}
				}
				else {
					if (tmp.size() == 0) {	//다 없는 경우
						input[location[input[i].pid].loc[0]] = input[i];
						fault++;

						update(i, 0);
					}
					else {	//몇 개만 없는 경우
						int l_cycle = location[input[i].pid].loc.size(), t_cycle = tmp.size();
						for (int l_index = 0; l_index < l_cycle; l_index++) {	//location index
							bool check = true;
							for (int t_index = 0; t_index < t_cycle; t_index++) {	//tmp index
								if (input[location[input[i].pid].loc[l_index]].pid == tmp[t_index].pid) {
									if (location[input[i].pid].pnum[l_index] == tmp[t_index].pnum) {
										check = false;
										break;
									}
								}
							}

							if (check) {
								input[location[input[i].pid].loc[l_index]] = input[i];
								fault++;

								update(i, l_index);
								break;
							}
						}
					}
				}
			}
		}
		else add_node(i);
	}
}

int main() {
	inp >> k;

	while (1) {	//input, location
		input_node node;
		inp >> node.pid >> node.pnum;

		if (node.pid == -1 && node.pnum == -1) break;

		input.push_back(node);
	}

	fifo();
	out << "FIFO: " << fault << '\n';
	restore();

	lru();
	out << "LRU: " << fault << '\n';
	restore();

	opt();
	out << "OPT: " << fault << '\n';
	print();

	inp.close();
	out.close();
	return 0;
}