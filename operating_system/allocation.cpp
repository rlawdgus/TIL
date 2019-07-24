#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 1001
#define INF 2147438647
using namespace std;

typedef struct Process {
	int pid;
	int start;
	int burst;
	int size;
}Process;

typedef struct Memory {
	int address;
	int pid;
	int size;
	int dest;
}Memory;

typedef struct Heap {
	int index;
	int size;
}Heap;

bool compare_worst(Heap &a, Heap &b) {
	if (a.size == b.size) return a.index < b.index;
	return a.size > b.size;
}
bool compare_best(Heap &a, Heap &b) {
	if (a.size == b.size) return a.index < b.index;
	return a.size < b.size;
}
bool allocate(Memory &memory, Process &process) {
	return memory.size >= process.size;
}
bool allocate_process(vector< Memory > &memory, Process &process, int index, int time);
bool release_memory(vector< Memory > &memory, int time);
bool allocate_queue(vector< Memory > &memory, vector< Process > &ready_queue, int time, int type);
bool allocate_fit(vector< Memory > &memory, vector< Process > &ready_queue, int front, int time, int type);
int firstFit();
int bestFit();
int worstFit();

int n, result;
Process process[MAX];
ifstream inp("allocation.inp");
ofstream out("allocation.out");

int main() {
	inp >> n;
	for (int i = 0; i < n; i++) {
		inp >> process[i].start >> process[i].burst >> process[i].size;
		process[i].pid = i;
	}

	out << firstFit() << endl << bestFit() << endl << worstFit();

	return 0;
}

bool allocate_process(vector< Memory > &memory, Process &process, int index, int time) {
	if (process.pid == n - 1) {
		result = memory[index].address;
		return true;
	}

	memory[index].pid = process.pid;
	memory[index].dest = time + process.burst;

	if (memory[index].size > process.size) {
		Memory newMemory = { memory[index].address + process.size, -1, memory[index].size - process.size, INF };
		memory[index].size = process.size;
		memory.insert(memory.begin() + index + 1, newMemory);
	}
	return false;
}

bool release_memory(vector< Memory > &memory, int time) {
	bool check = false;
	for (int i = 0; i < memory.size(); i++) {
		if (time == memory[i].dest) {
			memory[i].pid = -1;
			memory[i].dest = INF;
			check = true;
		}
	}
	for (int i = 0; i < memory.size() - 1; i++) {
		if (memory[i].pid == memory[i + 1].pid) {
			memory[i].size += memory[i + 1].size;
			memory.erase(memory.begin() + i + 1);
			i--;
		}
	}
	return check;
}

bool allocate_queue(vector< Memory > &memory, vector< Process > &ready_queue, int time, int type) {
	if (type == 0) {
		for (int i = 0; i < memory.size(); i++) {
			if (memory[i].pid == -1) {
				for (int j = 0; j < ready_queue.size(); j++) {
					if (allocate(memory[i], ready_queue[j])) {
						if (allocate_process(memory, ready_queue[j], i, time)) return true;

						ready_queue.erase(ready_queue.begin() + j);
						j--;
						break;
					}
				}
			}
		}

		return false;
	}
	else {
		for (int i = 0; i < ready_queue.size(); i++) {
			vector< Heap > heap;
			bool check = false;
			for (int j = 0; j < memory.size(); j++) {
				if (memory[j].pid == -1 && allocate(memory[j], ready_queue[i])) {
					heap.push_back({ j, memory[j].size });
					check = true;
				}
			}

			if (check) {
				if(type == 1) sort(heap.begin(), heap.end(), compare_best);
				else sort(heap.begin(), heap.end(), compare_worst);

				if (allocate_process(memory, ready_queue[i], heap[0].index, time)) return true;

				ready_queue.erase(ready_queue.begin() + i);
				i--;
			}
		}
		return false;
	}
}

bool allocate_fit(vector< Memory > &memory, vector< Process > &ready_queue, int front, int time, int type) {
	if (type == 0) {
		for (int i = 0; i < memory.size(); i++) {
			if (memory[i].pid == -1) {
				if (allocate(memory[i], process[front])) {
					if (allocate_process(memory, process[front], i, time)) return true;
					else return false;
				}
			}
		}

		ready_queue.push_back(process[front]);
		return false;
	}
	else {
		vector< Heap > heap;
		bool check = false;
		for (int i = 0; i < memory.size(); i++) {
			if (memory[i].pid == -1 && allocate(memory[i], process[front])) {
				heap.push_back({ i, memory[i].size });
				check = true;
			}
		}

		if (check) {
			if(type == 1) sort(heap.begin(), heap.end(), compare_best);
			else sort(heap.begin(), heap.end(), compare_worst);

			if (allocate_process(memory, process[front], heap[0].index, time)) return true;
		}
		else ready_queue.push_back(process[front]);

		return false;
	}
}

int firstFit() {
	int front = 0, time = 0;
	vector< Memory > memory;
	vector< Process > ready_queue;
	memory.push_back({ 0, -1, 1000, INF });
	while (true) {
		if (release_memory(memory, time)) {
			if (!ready_queue.empty() && allocate_queue(memory, ready_queue, time, 0)) return result;
		}
		while (time == process[front].start) {
			if (allocate_fit(memory, ready_queue, front, time, 0)) return result;

			front++;
		}
		time++;
	}
}

int bestFit() {
	int front = 0, time = 0;
	vector< Memory > memory;
	vector< Process > ready_queue;
	memory.push_back({ 0, -1, 1000, INF });
	while (true) {
		if (release_memory(memory, time)) {
			if (!ready_queue.empty() && allocate_queue(memory, ready_queue, time, 1)) return result;
		}

		while (time == process[front].start) {
			if (allocate_fit(memory, ready_queue, front, time, 1)) return result;

			front++;
		}
		time++;
	}
}

int worstFit() {
	int front = 0, time = 0;
	vector< Memory > memory;
	vector< Process > ready_queue;
	memory.push_back({ 0, -1, 1000, INF });
	while (true) {
		if (release_memory(memory, time)) {
			if (!ready_queue.empty() && allocate_queue(memory, ready_queue, time, 2)) return result;
		}

		while (time == process[front].start) {
			if (allocate_fit(memory, ready_queue, front, time, 2)) return result;

			front++;
		}
		time++;
	}
}