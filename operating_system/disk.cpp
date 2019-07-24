#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 2147438647
using namespace std;

struct request {
	int time;
	int location;
};

ifstream inp("disk.inp");
ofstream out("disk.out");

vector< request > input;
int run = 0, now = 0, serve;

bool compare_sstf(request a, request b) {
	return abs(now - a.location) < abs(now - b.location);
}

bool compare(request a, request b) {
	return a.location < b.location;
}

void fcfs() {
	for (int i = 0; i < input.size(); i++) {
		if (run > input[i].time) run += abs(now - input[i].location) + serve;
		else run += input[i].time - run + abs(now - input[i].location) + serve;

		now = input[i].location;
	}

	out << run << ' ' << now;
}

void sstf() {
	int index, input_size;
	while (1) {
		index = 0;
		input_size = input.size();
		for (int i = 0; i < input_size; i++) {	//탐색 범위
			if (run >= input[i].time) index = i + 1;
			else break;
		}

		if (index) {
			sort(input.begin(), input.begin() + index, compare_sstf);


			run += abs(now - input[0].location) + serve;
			now = input[0].location;

			input.erase(input.begin());
		}
		else run = input[0].time;

		if (input_size == 1) {	//마지막 처리
			out << run << ' ' << now;
			return;
		}
	}
}

void look() {
	int index, input_size;
	bool way = true;
	while (1) {
		index = 0;
		input_size = input.size();
		for (int i = 0; i < input_size; i++) {	//탐색 범위
			if (run >= input[i].time) index = i + 1;
			else break;
		}

		if (index) {
			if (way) {	//오른쪽
				sort(input.begin(), input.begin() + index, compare_sstf);
				
				for (int i = 0; i < index; i++) {
					if (now <= input[i].location) break;
					else if (i == index - 1) way = false;
				}
				run += abs(now - input[0].location) + serve;
				now = input[0].location;

				input.erase(input.begin());
				input_size--;
			}
			else {	//왼쪽
				sort(input.begin(), input.begin() + index, compare_sstf);

				for (int i = 0; i < index; i++) {
					if (now >= input[i].location) break;
					else if (i == index - 1) way = true;
				}
				run += abs(now - input[0].location) + serve;
				now = input[0].location;

				input.erase(input.begin());
				input_size--;
			}
		}
		else run = input[0].time;

		if (input_size == 0) {	//마지막 처리
			out << run << ' ' << now;
			return;
			
		}
	}
}

int main() {
	string name;
	int time, location;

	inp >> name >> serve;
	while (1) {
		inp >> time >> location;
		if (time == -1 && location == -1) break;

		input.push_back({ time, location });
	}

	if (name == "FCFS") fcfs();
	else if (name == "SSTF") sstf();
	else look();

	inp.close();
	out.close();
	return 0;
}